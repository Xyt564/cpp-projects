## SIM Signal Locator (ncurses Prank)

A **terminal-based prank program** written in C++ using **ncurses** that simulates locating and decrypting a mobile SIM / phone number.

Despite how intense it looks, this program **does not perform any real network operations**.
It’s entirely visual — just terminal UI, animations, and fake diagnostics.

This project was made for fun, to mess with a friend, and to **refresh my C++ skills** after not actively using C++ during college.

---

## 📌 What This Is

* A **fake SIM / signal locator**
* Built with **ncurses** for full-screen terminal UI
* Animated spinners, stats, and progress bars
* Fake “secure execution” popup with scrolling hex data
* Always ends in a **controlled failure**

👉 No real SIM access
👉 No carrier interaction
👉 No network scanning
👉 No phone number usage beyond display

It’s terminal cosplay.

---

## 🎯 Why I Made This

* Prank a friend with something that *looks* very serious
* Practice and revisit:

  * `ncurses` window management
  * Terminal UI layout & redraws
  * Threads and timing (`std::thread`, `std::chrono`)
  * Randomized output for realism
* Get back into C++ after focusing on other things in college

---

## 🛠️ How It Works (High-Level)

1. Initializes an ncurses session
2. Prompts for a “SIM / MSISDN target” (purely cosmetic)
3. Displays a fake scanning phase:

   * Signal strength values
   * Tower sync stats
   * Animated spinner
4. Opens a centered **popup window**:

   * “Secure execution environment”
   * Randomized hex dumps
   * Progress bar with slowing execution
5. Returns to the main screen
6. Ends with a fake error and terminates

All values, delays, and messages are randomized or hardcoded for effect.

---

## ▶️ Build & Run

### Requirements

* Linux or macOS
* `ncurses` installed

### install ncurses

```bash
sudo apt install libncurses-dev
```

### Compile

```bash
g++ simfinder2.cpp -o simfinder2 -lncurses
```

### Run

```bash
./simfinder2
```

> ⚠️ Best experienced in a real terminal.
> This will **not** work correctly inside most IDE consoles.

---

## ❗ Disclaimer

This program is **not real** and **not functional** as a SIM locator or signal scanner.

It does **not**:

* Access mobile networks
* Interact with SIM cards
* Track or locate phone numbers
* Bypass carrier systems

It is not hacking, spying, or illegal — just a visual simulation.

---

## 🧠 Notes

* All hex output is randomly generated
* Signal values are intentionally exaggerated
* The program always fails by design
* `ncurses` handles all screen drawing and cleanup

---

## 📚 License

Do whatever you want with it.
If someone believes it’s real, that’s part of the prank 😈

---
