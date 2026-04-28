# 🌲 Timberman Game (SFML - C++)

## 📌 Overview

This is a **Timberman-style arcade game** developed using **C++ and SFML**.
The player chops a tree while avoiding falling branches and managing time. The objective is to score as high as possible before time runs out or the player gets hit.

---

## 🧠 Game Logic

* Player chops the tree from **left or right**
* Each chop:

  * Increases score
  * Adds a small amount of time
  * Moves branches downward
* Random branches appear on either side
* Player must avoid being hit by a branch
* Time continuously decreases

---

## 🎯 Features

* Smooth animation using **delta time**
* Random branch generation (procedural logic)
* Score and timer system
* Sound effects (chop action)
* Moving background elements (clouds, bee)
* Collision detection (player vs branch)
* Restart and pause functionality

---

## 🎮 Controls

| Key     | Action               |
| ------- | -------------------- |
| ⬅ Left  | Chop from left       |
| ➡ Right | Chop from right      |
| ⏎ Enter | Start / Restart game |
| ␣ Space | Pause / Resume       |

---

## 📂 Project Structure

```id="c6q2vd"
main.cpp         → Main game loop and logic
graphics/        → Images (tree, player, branches, etc.)
sound/           → Audio files (chop sound)
font/            → Font file (KOMIKAP_.ttf)
```

---

## ⚙️ Requirements

* C++ Compiler (g++, MSVC, etc.)
* SFML Library (Graphics + Audio modules)

---

## ▶️ How to Run

1. Install SFML
2. Compile:

   ```bash
   g++ main.cpp -o timber -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```
3. Run:

   ```bash
   ./timber
   ```

---

## 🎮 Gameplay Flow

```id="1h9p0q"
Start Game →
Chop Tree →
Branches Move Down →
Avoid Branch →
Score ↑ →
Time ↓ →
Game Over (hit branch / time out)
```

---

## ⚡ Key Concepts Used

* Game loop structure
* Object movement with delta time
* Collision detection
* Procedural generation (random branches)
* State management (pause, game over)

---

## 🚀 Future Improvements

* Add background music 🎵
* Add difficulty levels
* Add combo scoring system
* Add mobile/touch controls

---

## 🧾 Summary

This project demonstrates how to build a **real-time 2D game using SFML**, including animations, physics, and user interaction.

---

## 👨‍💻 Author

Your Name
