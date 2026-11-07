# Candy_Crush

these are the instructions:

if you are seeing this then it means you already have been added as a collaborator in the repo "Candy-Crush"
if you know how to clone a repo which we have learnt in ICT you may skip to line 18

now you should have github desktop on your system
if you have skip this part otherwise see this video to download it:
https://www.youtube.com/watch?v=G4SIIp14Xx4

once you have downloaded it you have to sign in with the same university mail from which you accepted the collab invitation on github

after that you would be seeing clone repo option, select it, then you will also be shown a url option select it then add this link
https://github.com/l262058-tauzsadiq/Candy_Crush
remember the path where you cloned it 



now go to path you will be seeing a "Candy_Crush" folder open it then there would be another folder "game" which you have to open in vs code. it also contains git files dont change them
remember this folder "game" is setup for sfml only on vs code other IDE wont work. dont open "Candy_Crush" folder on vs code it must be "game" folder 

in the game folder there is ".vscode" and "scripts" folder which have compiler settings then "lib" folder which contains sfml files
there is "build" folder which have 3 .dll files. we dont have concern with them. this folder is important because this is the one where our executable file will be generated named as "candy_crush.exe"
note: right now you wont be seeing it but later you will

next we have main.cpp and prototype.h
there is another folder named as "subfolders_for_game"

you dont have to change any of the file we will be working only on main.cpp, prototype.h and subfolders_for_game 

now here are is the most difficult part

the latest version of sfml is 3.1 but we will be using sfml 2.6.2 it is because this version is more simplified, stable and also has every functionality we will be needed
there is an issue using sfml that it only works for specific compilers 
for sfml 2.6.2 the compiler is g++ 13.1.0 
therefore your system must have this compiler configured 
for this purpose you have to first download the compiler you will find it in the cloned repo on your system named as
winlibs...

now cut it and paste it anywhere else than extract all the files
now you have to open the folder then there would be mingw64 folder open it than select bin folder right click copy path
now go to windows search, type edit the system variables, open it, than open environment variable, 
now you can see "user variables for dell", double click path in it than select new, after that paste the copied path from previous step. then ok ok ok

now your vs code is completely setup for sfml
all you have to do is to restart vs code, open game folder, go to main.cpp press ctrl+shift+b
your file will be compiled and then you should be able to see "candy_crush.exe" in build folder

there are two ways run that file
open the file directly from windows explorer
open the file from vs code terminal using this command
.\build\candy_crush.exe
in terminal
if you are not being shown terminal than press ctrl+shift+` (upper key of tab) 

after that you would be shown output consisting of window screen, it will be completely black with candy crush written on top right corner

now the vs code is set up and now we can move to the project


