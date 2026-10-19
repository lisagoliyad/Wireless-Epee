# Wireless Épée

A wireless replacement for the wired body-cord scoring system used in épée fencing.

In épée, a touch is registered when the tip of the blade is depressed, closing a circuit that runs through a wired body cord and reel to the scoring box. This project replaces that physical connection with a small radio link: a transmitter on the fencer detects the tip closing and sends a message to a receiver connected to the scoring side, which lights an indicator.

## How it works

```
 Épée tip switch ──► Transmitter (Arduino + radio module) ))) radio ((( Receiver (Arduino + radio module) ──► Indicator LED
```

- **Transmitter** (`Software_Serial_Transmitter.ino`): reads a push button on pin 4 (standing in for the épée tip switch). While the button is pressed, it sends `H` over the radio using the module's `AT+SEND` command and lights a local LED on pin 5. It then sends `L` when the pulse ends.
- **Receiver** (`Software_Serial_Reciever.ino`): listens on the serial port for incoming radio messages. When a message containing `H` arrives, it lights an LED on pin 3 for one second.

Both sketches talk to the radio module over the Arduino's hardware serial port using AT-style commands.

## Repository contents

| File | Description |
|---|---|
| `Software_Serial_Transmitter.ino` | Arduino sketch for the transmitter unit |
| `Software_Serial_Reciever.ino` | Arduino sketch for the receiver unit |
| `Wireless Épée Circuit Diagram.kicad_sch` | Circuit schematic (open with [KiCad](https://www.kicad.org/)) |
| `Wireless Épée Case Model.url` | Link to the 3D model of the enclosure |
| `Wireless Épée Concept Map.pdf` | Concept map of the system and design considerations |
| `Wireless Épée 1 year Research Paper.pdf` | Write-up of the one-year research project |
| `Wireless Épée 1 year Research Poster.pdf` | Research poster summarizing the project |

## Hardware

- 2 × Arduino-compatible microcontroller boards (one per unit)
- 2 × serial radio modules that accept `AT+SEND` commands
- Push button (prototype stand-in for the épée tip switch)
- 2 × LEDs with current-limiting resistors
- Batteries or other power source for each unit

See the KiCad schematic for the full wiring.

## Pin assignments

| Unit | Pin | Function |
|---|---|---|
| Transmitter | 4 | Push button input |
| Transmitter | 5 | Status LED |
| Receiver | 3 | Indicator LED |

## Getting started

1. Open the schematic in KiCad and wire up both units.
2. Open `Software_Serial_Transmitter.ino` in the Arduino IDE, select your board and port, and upload it to the transmitter unit.
3. Open `Software_Serial_Reciever.ino` and upload it to the receiver unit.
4. Power both units and press the button on the transmitter. The receiver's LED should light.

Disconnect the radio module from the serial pins while uploading if your board shares the hardware serial port with the USB connection.

## Background

The research paper and poster describe the motivation, design decisions, testing, and results in detail. Start there for the full context.

## Status

Prototype / research project. The current code demonstrates the transmit-and-receive link with a push button in place of a real tip switch.
