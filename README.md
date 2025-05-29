# CSC4750: Internet Protocol Stack Simulation Assignment

## Authors: Chris Kendall, Kyler Veenstra

## Source Code Files

- layerinterface.h: Defines the abstract base class LayerInterface that all network layers inherit from.
- application.h / .cpp: Implements the Application Layer of the network stack. And (similarly for all other layers):
  - Encapsulate() prepends APP_HDR| to outgoing messages.
  - Decapsulate() removes APP_HDR| from incoming messages.
  - Prints message state during sending and receiving.
- link.h / .cpp: Implements the Transport Layer.
- network.h / .cpp: Implements the Network Layer.
- transport.h / .cpp: Implements the Link Layer.
- main.cpp: Controls the simulation's execution flow.

## How to Build/Run

- From within network_sim directory: Terminal > Run Task > Run Program