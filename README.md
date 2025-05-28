# CSC4750: Internet Protocol Stack Simulation Assignment

## 5/28 - 2:45pm TODO: 

### ✅ Core Tasks

* [x] Implement `Encapsulate()` for each layer. *(Done)*
* [x] Maintain a queue for message transfer. *(Done)*
* [x] Implement `Decapsulate()` for each layer (removing the layer's header). *(Done)*

### ❗ Must-Do Tasks

* [ ] Add console print statements for both `Encapsulate()` and `Decapsulate()` similar to assignment example.
* [ ] Modify `main.cpp` to:

  * Show a complete `==== Sending ====` section
  * Then show a `==== Receiving ====` section
  * Iterate through `Decapsulate()` in reverse order.
* [ ] Fix `LayerInterface`:

  * Make `Encapsulate` and `Decapsulate` pure virtual (`= 0`)
  * Add a `virtual ~LayerInterface() {}` destructor.
* [ ] Implement `get_messages_from_queue()` or remove it if unused.

### 🧹 Cleanup / Quality Tasks

* [ ] Call `delete` on all `new`-created layer pointers in `main.cpp`.
* [ ] Consider renaming `ToString()` in `LinkLayer` or removing it if unused.
* [ ] Optionally add comments or a `README.md` to explain each file's role.

---

## 📌 Bonus Features (Optional, from assignment)

* [ ] Implement checksum at the transport layer.
* [ ] Simulate dropped/corrupted packets.
* [ ] Implement basic ARP and device abstraction.

## Objective

Your group will implement a C++ simulation of the Internet protocol stack focusing on four core layers:  
- **Application**  
- **Transport**  
- **Network**  
- **Link**  

> **Note:** The **Physical** layer is excluded.

Your simulation will demonstrate encapsulation during data transmission and decapsulation during reception, using simple headers at each layer and terminal output to show layer-by-layer data flow.

---

## Project Structure

Organize your project as follows:


network_sim/
├── main.cpp
├── layers/
│   ├── application.h / .cpp
│   ├── transport.h / .cpp
│   ├── network.h / .cpp
│   └── link.h / .cpp
└── .vscode/
└── tasks.json

---

## Requirements

- **Encapsulation**:  
  Each layer must prepend a header string to the data it receives from the layer above.

- **Decapsulation**:  
  As data is received at each layer, the corresponding header must be removed.

- **Console Output**:  
  Each layer must clearly print messages during both sending and receiving, showing the data it processes.

- **Modular Code**:  
  Each layer must be implemented in its own header (`.h`) and source (`.cpp`) files. Use functions for `Send` and `Receive` operations.

- **VS Code Integration**:  
  A valid `tasks.json` file must be included to allow building and running from the VS Code task runner.

---

## Extensions (Optional)

If you're looking to challenge yourself, consider adding:

- ARP resolution at the **Link** layer  
- Checksums in the **Transport** layer  
- Simulated corruption or packet drop

---

## Sample Output

Message sent: Hello, Network!

==== Sending ====
[Application Layer] Sending: Hello, Network!
[Transport Layer] Sending: APP_HDR|Hello, Network!
[Network Layer] Sending: TRANS_HDR|APP_HDR|Hello, Network!
[Link Layer] Sending: NET_HDR|TRANS_HDR|APP_HDR|Hello, Network!

==== Receiving ====
[Link Layer] Receiving: LINK_HDR|NET_HDR|TRANS_HDR|APP_HDR|Hello, Network!
[Network Layer] Receiving: NET_HDR|TRANS_HDR|APP_HDR|Hello, Network!
[Transport Layer] Receiving: TRANS_HDR|APP_HDR|Hello, Network!
[Application Layer] Receiving: APP_HDR|Hello, Network!

Final message received: Hello, Network!

---

## Deliverables

1. C++ source code implementing the simulation.
2. VS Code project configuration (`tasks.json`).
3. Sample output of a run session (can be included as a comment in `main.cpp` or as `sample_output.txt`).
4. `README.md`  
   > Briefly describe what each file does and how to build/run the project.

---

## Submission

- Create a **Public GitHub Repository** for the project.
- Submit the **URL of the Repository on Canvas**.