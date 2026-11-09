// Candy Collector!
a game where you collect candy and try to collect the bad ones
if you do, youll get a spooky.. surprise

what i like: i like that my game actually forces me to lock in and win because its actually kind of tricky sometimes
and i like the satisfying popping sound when i collect the right ones (: !!!!

thanks cloveian for the feedback/suggestion to save scores!

HOW TO DOWNLOAD AND RUN:
step 1: go to https://github.com/Zaaoooow/Week3CandyCollect/releases/tag/v1.0.0
step 2: download the Week3CandyCollect.Zip
step 3: extract the zip folder
step 4: run the main.exe file !
step 5: PLAY IT!


<img width="1268" height="730" alt="Screenshot 2026-11-08 192718" src="https://github.com/user-attachments/assets/b30c77a7-5b9f-41dd-9d9a-8730e440f8f1" />


first hour:
textures -
- main menu background
- gamemode background
- play, settings, and quit buttons
- classic mode button
- hovered versions of the buttons
functional:
- made the play button functional
- made the quitbutton functional
- implemented all images into the game.

second hour:
textures:
- created pixelart for settings page
- created normal and hovered versions of settings exit button
- created normal and hovered versions of hard mode button for gamemode screen
sounds:
- added theme music to the game
- added click sfx to buttons that go to the next screen
functional:
- play button
- quitbutton
- settings button
- audio on/off setting
- settings exit
new thigns learned:
- lerned how to use raylibs musicstream functions and sounds.

third hour:
textures:
- created etxtures for the back button and hvoered version
- created classic mode background
- created and candy1 texture
functional:
- back button
- classic mode screen
- initially used drawrcirclv to make candies but thought it didnt match my pixelart
  so i changed it to a pixel art candy whic made it harder to calculate the collision
- added three candies that move at different speeds.
- made it so clicking a candy increases the score and spawns a new candy from the bottom
new things learned:
- used arrays and forloops to give each individual candy its own attributes and give them different
  speeds and positinos more easily.

fourth hour/fifth hour:
forgot to commit for one hour so its combined:
sounds added:
- correct candy sfx
- wrong candy sfx
- jumpscare sfx
textures made:
- second candy textuere (candy2)
- two bad candy texture (badcandy, badcandy2)
- game loss screen
- jumpscare mosnster
- playagain adn hovered version
functional:
- added a scorying system
- kuves ststen
- game over screen
- play again, not fully functional yet
- jumpscare when bad candies touched
- custom mouse cursor and trail
- basic physics, and gravity to make the candy falll back down
- randomized candies with 4 types
- integrated sfx into the gameplay
psst: this was when i started bulletpointing my individual things that i added
lemme know if this way is better

sixth hour:
textures:
- game win screen
- play again button for win screan and hovered version
- hardmode background
sounds:
- classic mode music
- lose screen music
- win screen music
functional:
- fniished remaining of classic mode
- made playbutton restart the new game scores
- made it so hardmode leads to screen 3
- integrated new music into the game
currently working on:
- making hardmode gameplay
- debug debug debug

seventh hour:
functional: 
- hardmode with 5 candies, one life and a score goal of 45
- added win/lose screens and play again button and hovered an jumpscare effects
- candy reset when hit or out of screen
- all of this for hardmode
textures:
reused candy textures from classicmode, jumpscare, win/lose, playagain
sounds:
- added sounds to all interactables and theme musics

eighth hour:
textures:
- added guide button and hvoered version
- guide page with exit button and hovered version
- stats button with hovered version
functions:
- added the guide button to main menu
- made the guide button functional and impleemnted the guide page
- write the game guide explaining how to play
- main menu fniished
- added stats button to gamemode screen, functional yet

ninth hour:
textures:
- made stats page
- stats exit and hovered version
sounds:
- added sounds stats
functionals:
- stat page and exit
- connected stats to game like, games played, wrongs, rights, wins, losses,
  streaks, and a highstreak, missed, and a winrate.
- connected it to both ghardmode and classicmode
new things to add:
thanks to CLOVEIAN! who suggested to add and make my statistics and scores savem
so i will try and learn that - hopefully its not hard

tenth hour:
textures:
- added reset and save buttons to stats page, and hovered versions.
- added music on and off button textures to settings page
functional:
- all game features shoudl work now!
- added automatic score saving system
- added a mnual save button in stats page just in case
- added a reset button in stats page
new things learned: i learned how to use ifstream ofstream from the fstream
library in c++ which allows me to store, read, or laod info to or from files
I actually needed to learn this because im participating in my schools
hpe certification section c for 004 which requires me to know it
so thanks to cloveian i now understand it !
