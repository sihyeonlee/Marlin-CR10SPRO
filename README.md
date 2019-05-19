# Marlin CR-10S Pro Firmware
<img align="top" width=175 src="logo/marlin-250.png" />

## Info

해당 펌웨어는 TinyMachines B6를 기반으로 다시 수정하였습니다.

수정 전의 원래 펌웨어는 [TinyMachines-Marlin-B6](https://github.com/InsanityAutomation/Marlin/tree/Creality_DWINTest)에서 확인 할 수 있습니다.


## Recent Changes
- [TinyMachines-Marlin-B6](https://github.com/InsanityAutomation/Marlin/blob/Creality_DWINTest/README.md) Recent Changes 참조
- HOMMING_POINT 변경 (50, 50) > (130, 150)
- HOMMING_FEEDRATE 변경
- Z_MAX_FEEDRATE 변경
- NOZZLE HEATING PID OPTION 변경
- AUTO LEVELING POINT 증가 4 > 5
- MAX_BED_SIZE 변경
- Z_CLEARANCE_PROBE 변경
- MULTI AUTO LEVELING 제거
- FAN_SOFT_PWM 활성화
- SOFT_PWM_SCALE 변경
- MANUAL_MOVEMENT_FEEDRATE 수정
- 시작할 때 및 전체적인 사운드 음소거


## License
Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.