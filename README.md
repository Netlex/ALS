# Advanced Locomotion System V4 on C++

Оптимизированная и реплицируемая C++ (Plugin) версия на основе [Advanced Locomotion System V4](https://www.unrealengine.com/marketplace/en-US/product/advanced-locomotion-system-v1) для **Unreal Engine 4.25+**

## Особенности
- Вы можете сразу же начать использовать его в своем проекте, не внося никаких серьезных изменений в конфигурацию проекта.
- Исходный код сильно оптимизирован при переносе из Blueprints. Для 100 персонажей на сцене процессорное время уменьшается с ~17 мс до ~10 мс.
- Оптимизирована производительность сети и поставляется с полной поддержкой репликации. Плагин ALS в настоящее время превосходит по производительности сети ALS V3 и ALS V4 на основе BP:
```
Advanced Locomotion System V3 (BP):
Общая исходящая пропускная способность составляет 686 КБ в течение 60 секунд (30 секунд на сервере, 30 на клиенте).
Данные Character Actor, передаваемые по сети - 43 КБ
Данные 'ReplicatedMovement', передаваемые по сети - 19 КБ
Самые высокие данные RPC, передаваемые по сети - 90 КБ
Общие свойства объекта - 46 КБ
Общий размер RPC - 201 KB

Advanced Locomotion System V4 (BP):
Общая исходящая пропускная способность составляет 2.7 МБ в течение 60 секунд (30 секунд на сервере, 30 на клиенте).
Данные Character Actor, передаваемые по сети - 116 КБ
Данные 'ReplicatedMovement', передаваемые по сети - 45 КБ
Самые высокие данные RPC, передаваемые по сети - 536 КБ
Общие свойства объекта - 209 КБ
Общий размер RPC - 1.7 МB

Advanced Locomotion System V4 (C++):
Общая исходящая пропускная способность составляет 618 КБ в течение 60 секунд (30 секунд на сервере, 30 на клиенте).
Данные Character Actor, передаваемые по сети - 38 КБ
Данные 'ReplicatedMovement', передаваемые по сети - 14 КБ
Самые высокие данные RPC, передаваемые по сети - 48 КБ
Общие свойства объекта - 41.1 КБ
Общий размер RPC - 91.1 KB
```

## Настройка Плагина
- Клонируйте репозиторий, если вы работаете над проектом C++ или загрузите последнюю версию, если вы работаете над проектом BP.
- Переместите папку ALS в папку "Plugins" вашего проекта
- В конфигурационный файл `DefaultInput.ini` нужно добавить следующее (если файл `DefaultInput.ini` не найден создайте его):
```
[/Script/Engine.InputSettings]
+ActionMappings=(ActionName="JumpAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=SpaceBar)
+ActionMappings=(ActionName="JumpAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=Gamepad_FaceButton_Bottom)
+ActionMappings=(ActionName="StanceAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=LeftControl)
+ActionMappings=(ActionName="SprintAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=LeftShift)
+ActionMappings=(ActionName="StanceAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=Gamepad_FaceButton_Right)
+ActionMappings=(ActionName="SprintAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=Gamepad_LeftThumbstick)
+ActionMappings=(ActionName="WalkAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=LeftAlt)
+ActionMappings=(ActionName="WalkAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=Gamepad_RightShoulder)
+ActionMappings=(ActionName="AimAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=RightMouseButton)
+ActionMappings=(ActionName="AimAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=Gamepad_LeftTrigger)
+ActionMappings=(ActionName="UseAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=E)
+ActionMappings=(ActionName="FireAction",bShift=False,bCtrl=False,bAlt=False,bCmd=False,Key=LeftMouseButton)
+AxisMappings=(AxisName="MoveForward/Backwards",Scale=1.000000,Key=W)
+AxisMappings=(AxisName="MoveRight/Left",Scale=1.000000,Key=D)
+AxisMappings=(AxisName="LookUp/Down",Scale=-1.000000,Key=MouseY)
+AxisMappings=(AxisName="LookLeft/Right",Scale=1.000000,Key=MouseX)
+AxisMappings=(AxisName="MoveForward/Backwards",Scale=-1.000000,Key=S)
+AxisMappings=(AxisName="MoveRight/Left",Scale=-1.000000,Key=A)
+AxisMappings=(AxisName="MoveForward/Backwards",Scale=1.000000,Key=Gamepad_LeftY)
+AxisMappings=(AxisName="MoveRight/Left",Scale=1.000000,Key=Gamepad_LeftX)
+AxisMappings=(AxisName="LookUp/Down",Scale=1.000000,Key=Gamepad_RightY)
+AxisMappings=(AxisName="LookLeft/Right",Scale=1.000000,Key=Gamepad_RightX)
```
- В конфигурационный файл `DefaultEngine.ini` нужно добавить следующее:
```
[/Script/Engine.CollisionProfile]
+Profiles=(Name="ALS_Character",CollisionEnabled=QueryAndPhysics,bCanModify=True,ObjectTypeName="Pawn",CustomResponses=((Channel="Visibility",Response=ECR_Ignore),(Channel="Camera",Response=ECR_Ignore),(Channel="Climbable",Response=ECR_Ignore)),HelpMessage="Custom collision settings for the capsule in the ALS_BaseCharacter.")
+DefaultChannelResponses=(Channel=ECC_GameTraceChannel2,DefaultResponse=ECR_Block,bTraceType=True,bStaticObject=False,Name="Climbable")

[CoreRedirects]
+PackageRedirects=(OldName="/ALSV4_CPP",NewName="/ALS",MatchSubstring=true)
+PackageRedirects=(OldName="/ALSV4_CPP",Removed=true)
+PackageRedirects=(OldName="/ALS/AdvancedLocomotionV4",NewName="/ALS",MatchSubstring=true)
+PackageRedirects=(OldName="/ALS/AdvancedLocomotionV4",Removed=true)
```
