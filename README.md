# Circuit Simulator

This is a simple digital logic circuit simulator.

## How to Run

1.  **Open in Visual Studio:**
    *   Navigate to the `Eindopdacht/build` directory.
    *   Open the `CircuitSimulator.sln` file with Visual Studio.

2.  **Set as Startup Project:**
    *   In the Solution Explorer, right-click on the **CircuitSimulator** project.
    *   Select "Set as StartUp Project".

3.  **Configure Command-Line Arguments:**
    *   Right-click on the **CircuitSimulator** project again and select "Properties".
    *   Go to the "Debugging" tab on the left.
    *   In the "Command Arguments" field, enter the relative path to the circuit file you want to test. The circuit files are located in the `Eindopdracht/circuits` directory.
    *   For example, to test `circuit1.txt`, you would enter: `../circuits/circuit1.txt`

4.  **Build and Run:**
    *   Build the solution (F7 or Build > Build Solution).
    *   Run the simulator (F5 or Debug > Start Debugging).

The output of the simulation will be displayed in the console.
