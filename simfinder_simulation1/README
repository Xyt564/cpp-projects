## Fake Network Ping (Terminal Prank)

A **terminal-based prank program** written in C++ that *looks* like it’s performing a network ping on a phone number — but doesn’t actually do anything malicious, network-related, or real.

This was made purely for fun and as a way to **refresh my C++ skills** after being away from active C++ development due to college.

---

## 📌 What This Is

* A **visual simulation** of a “network ping”
* Animated progress bar
* Randomized status messages
* Deliberately slow pacing to feel “real”
* Always ends in a **fake failure message**

👉 **No real network requests are made.**
👉 **No data is sent, received, or logged.**
👉 **The phone number is never used for anything.**

It’s basically a glorified loading screen 😅

---

## 🎯 Why I Made This

* Mess with a friend (successfully)
* Practice:

  * `std::thread` and `std::chrono`
  * Terminal control (ANSI escape codes)
  * Vectors, strings, randomization
  * Output buffering behavior
* Get back into the C++ mindset after not using it much during college

---

## 🛠️ How It Works (High-Level)

1. Clears the terminal using ANSI escape codes
2. Prompts for a “target phone number” (purely cosmetic)
3. Displays:

   * A header
   * Rotating fake status messages
   * A progress bar from 0% → 100%
4. Progress slows near the end for dramatic effect
5. Ends with a fake timeout error

---

## ▶️ Build & Run

### Compile

```bash
g++ simfinder.cpp -o simfinder
```

### Run

```bash
./simfinder
```

> ⚠️ Best experienced in a Unix-like terminal (Linux/macOS).
> ANSI colors and screen clearing may not behave correctly in some Windows terminals unless using WSL or a compatible shell.

---

## ❗ Disclaimer

This program is **not a real ping tool** and **does not interact with mobile networks, SIM cards, or phone numbers** in any way.

It is:

* Not hacking
* Not tracking
* Not spying
* Not illegal

Just terminal theater 🎭

---

## 🧠 Notes

* All delays and messages are intentionally exaggerated for realism
* The failure is hardcoded — it will *always* fail
* Output buffering is disabled to ensure smooth animation

---

## 📚 License

Do whatever you want with it.
If you prank someone, that’s on you 😈

---
