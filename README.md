# Public-Folder
Stuff to share with everyone
This was made in responce to a post that I found on UpWork
Here's the original post:

You need to create a simplistic text based linear game in c++: You have been hired by Magic Gaming company to create a program to play the game “Riders of Fortune”, which will be a text-based fantasy style board game. The game plays as follows:
You play Yarra, a young horseman in search of the of the illustrious Chalice of Knowledge, an artifact that will bring you everlasting wisdom.  The Chalice can only be found in dragon dungeon after defeating the dragon.
Yarra will have will have Experience Points (XP) that start at 0. He starts up with a knife, but can upgrade his weapon. He can also attack monsters and if he beats them, they will provide XP. 
The Game Board : The game board will always be displayed on the screen as an array of characters. 

Onscreen Map To Be Displayed:
P * * * * * * * * * * * * * * * * * * * * * * * * * * * * D

Mapping of spaces:
P 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 D
P: Corresponds to where the player is currently located (The player starts on space 1)
D: Corresponds to the last space, where the Dragon is
There are 28 positions on the board and the player starts in space 1. The player can only travel forward (higher numbers). The dungeon dragon is on space 28 marked with a D. The player obtains the Chalice if he can slay the dragon. You must keep track of the player’s current position and mark it on the onscreen map with P.
Player Movement:
You will provide the player with the following menu:
1)    Travel to another space on the board
2)    Dismount and explore the current space
If the player chooses option 1, a six-sided die will be rolled, and the player must move to that space.
If the player dismounts and explores the space the space the following can happen:
1)    The player encounters a monster and must battle
2)    The player finds a new weapon
3)    The area is empty, no change.
Outcome 1: Fights a monster
During initialization, randomly choose 14 spaces that will have a monster. The monsters will have an HP of 3 to 7 (You can decide when defining the monsters). 
The attack amount will be calculated by rolling a six-sided die plus the extra damage of the weapon being carried. If Yarra fails to destroy the monster on the first attack he will die.
If Yarra destroys the monster, he will gain XP of 2 per defeat.
Outcome 2:  Finds a new weapon:
There will be 5 weapons that can be found in the game. Each weapon will be allocated to a space. The weapon will give a modifier (an amount added to the result of the die roll).
•    Crossbow: +3 on attack
•    Flail:  +4 on attack
•    Broad Sword: +5 on attack
•    Dragon Slayer: +6 on attack
•    Spell of The Gods: +7 on attack
Have the program choose 5 random spaces that will contain the weapons instead of monsters (except for space 1, and 28). 
If you find a weapon which has an attack higher than the weapon you are carrying, equip the new weapon. Otherwise keep the weapon you previously had.
Outcome 3: Area is empty:
Have the program choose 7 random spaces that will be empty (will no contain a weapon or a monster)
Display the following message:
“There is nothing for you to do, so you reflect upon your adventures thus far. You take the time to train and enhance your reflexes”
Your XP increases by 1.
Encounter: 
If the player encounters a monster, the player must roll the die to obtain an attack value. The player’s weapon provides an additional attack value to the to the value of the die. If the player fails to kill the monster with the attack, the monster will destroy the player.
For example, if player rolls a 4 but they have a Broad Sword (+4), their total attack is 4 + 4 = 8
End Game:
If the player reaches spot 28 (by either rolling enough to get to 28 or rolling more than 28, the player will face the dragon only if his XP is equal to or higher than 5.
If he doesn’t have the XP required, the following message will display and end the game.
“Alas, the dragon’s eyes stare at you and places you under his spell. You try to move but fail to do so and find yourself torched by the dragon’s fire. If only you had more experience, you could have seen it coming.”
If the player does have the XP required, he will attack the dragon. The dragon will have an HP of 10. If he can kill the dragon, the following message will display:
“Due to your cunning and experience, you have defeated the deadly dragon. Your quest has ended good sir. You’ve obtained the Chalice of knowledge and all of earth’s mysteries are revealed.”
Additional Requirements:
1.    Make sure you always display the player stats ((XP) and Current Weapon).
2.    Make sure you display the result of the die roll
3.    Make sure you display the total attack.
4.    Make sure you display the HP of the monster you encounter.
