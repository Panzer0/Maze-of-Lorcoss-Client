# Multithreaded-game-client

The client side of the game. An active server (https://github.com/Panzer0/Multithreaded-game-server) is required in order for the client to function properly.   
The game utilises ncurses, a terminal-oriented C library.   
Since the entirety of the game is played through a terminal, its graphics are made up of ASCII symbols, much like the old-school classics. 

The goal of the game is to traverse a maze in search of different types of treasure.    
However, the task is made harder by beasts that roam the dungeon. Should they encounter a player character, they will begin to chase them. When trying to get away from one of the maze's denizens, the adventurer should beware of bushes, which can and will slow them down. 

Should a treasue hunter be vanquished, all of his gold remains on his corpse, free to reclaim, whether it be by the same player, or another adventurer willing to exploit the fallen one's misfortune. In order to prevent this, money can be stashed within the safety of the camp, which the beasts steer clear of. 

The game supports multiple simultaneous clients, which means that more than one adventurer can be present in the dungeon at the same time. That being said, adventuring is a competitive industry, and as such the players do not work towards a common goal. It is not unhead of for an opportunistic adventurer to lure the beast towards an unexpecting adventurer stuck in a dead end, or go for the more direct approach and clash with them face to face.

Due to the overwhelming darkness of the underworld, the adventurers can only see a couple of tiles away. The rest of the world, location of other adventurers included, is obfuscated. However, the player themself is not doomed to darkness and can freely switch between a day and night display mode, depending on their visual preference.

