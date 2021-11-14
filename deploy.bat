call "C:\D\Programowanie\libs\qt\6.2.1\msvc2019_64\bin\qtenv2.bat"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
rmdir "BUILD" /s /q
mkdir "BUILD"
cd C:\D\Programowanie\BoardGamesProjects\GameShare
ROBOCOPY "..\build-GameShare-Desktop_Qt_6_2_1_MSVC2019_64bit-Release\gui\main_app" BUILD main_app.exe
C:\D\Programowanie\libs\qt\6.2.1\msvc2019_64\bin\windeployqt.exe --release --qmldir gui\main_app\qml BUILD\main_app.exe