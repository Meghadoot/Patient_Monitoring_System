Design of PMS Middleware

🔹 IPC Handler (ipc_handler.c/h)

    Implements libdbus for message handling (POSIX compliance)

    Implements UDS for data exchange between HAL and Middleware

🔹 Data Manager (data_manager.c/h)

    Implements a Circular Buffer for fast data handling

    Synchronizes dataflow among HAL components & Middleware

🔹 Middleware core (middleware.c/h)

    Responsible to handle a data flow between HAL, IPC & external applications 

    Internally, Bridges IPC Handler &  Data Manager

    Manages system states & configuration

🔹 Configuration (middleware_config.h)

    Implementation Plan

🔹 IPC Handler (ipc_handler.c/h)

    Implements libdbus for message handling

    Implements UDS for data exchange between HAL and Middleware

🔹 Data Manager (data_manager.c/h)

    Implements a Circular Buffer for fast data handling

    Synchronizes data between HAL and Middleware

🔹 Middleware (middleware.c/h)

    Defines IPC modes (e.g., enable/disable D-Bus, Sockets)


High level depiction: 


   [ Applications / External Services ]
                 ↑
      ┌─────────────────────────────┐
      │     Middleware (Core)       │   ◄── Provides APIs via D-Bus + UDS
      │ ┌─────────────────────────┐ │
      │ │     IPC Handler         │ │   ◄── Handles D-Bus & UDS communication
      │ └─────────────────────────┘ │
      │ ┌─────────────────────────┐ │
      │ │     Data Manager        │ │   ◄── Circular buffer; queueing & sync
      │ └─────────────────────────┘ │
      │ ┌─────────────────────────┐ │
      │ │   HAL Interface Layer   │ │   ◄── Abstraction over UART, ADC, GPIO
      │ └─────────────────────────┘ │
      └─────────────────────────────┘
                 ↑
         [ HAL Drivers (src/hal) ]
                 ↑
        [ Kernel or Bare-Metal I/O ]
