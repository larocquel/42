*This project has been created as part of the 42 curriculum by leoaguia.*

## Description
NetPractice is a practical, introductory project designed to teach the fundamentals of computer networking. The primary goal of this project is to successfully configure small-scale simulated networks across 10 progressive levels. Through these exercises, you learn how to calculate and allocate IP addresses, configure subnet masks, establish connections between devices using routers and switches, and properly define routing tables and default gateways to ensure full network connectivity.

## Instructions

### Running the Training Interface
To launch the simulation environment:
1. Download the project file attached to the intranet page and extract it into a folder of your choice.
2. In your terminal, navigate to that folder and execute the `run.sh` script (`./run.sh`). This script will start a local web server and automatically open the training interface in your preferred web browser.
3. *Alternative:* If the `run.sh` script does not function properly due to browser constraints, you can manually start the server by running `python3 -m http.server 49242` (or another port of your choice) and then navigating to `http://localhost:49242` in your web browser.
4. On the main page, enter your intranet login so the Moulinette can generate your personal configuration.

### Exporting Configurations
When you successfully fulfill all the goals of a level (all status lines are "OK"), a `Get my config` button becomes available. Click this button to download your correct configuration as a `.json` file.

### Submission Requirements
To submit this project for peer-evaluation:
* You must complete all 10 levels available in the training interface.
* **10 exported configuration files (one per level) must be placed at the repository root**.

## Resources

### Networking Concepts Studied
To complete this assignment, a solid understanding of the following theoretical and practical concepts was required:
* **TCP/IP addressing** and IPv4 architecture.
* **Subnet masks** and Variable Length Subnet Masking (VLSM).
* **Default gateways** and static routing tables.
* The physical and logical roles of **routers and switches**.
* The fundamentals of **OSI layers** (particularly Layers 2 and 3).
* Public vs. Private IP Addresses (RFC 1918).

### Classic References
* [Cisco Networking Academy: IP Addressing and Subnetting](https://www.netacad.com/)
* [RFC 1918 - Address Allocation for Private Internets](https://datatracker.ietf.org/doc/html/rfc1918)
* [IBM Documentation: TCP/IP Tutorial and Technical Overview](https://www.redbooks.ibm.com/abstracts/gg243376.html)

### AI Usage
* **Tasks & Parts of the Project:** AI (Google Gemini) was utilized as an interactive tutor during the planning and troubleshooting phases of the network architectures (specifically from Levels 7 to 10).
* **How it was used:** The AI was prompted to clarify complex networking mechanics, such as explaining route summarization, debugging "multiple interface match" errors due to subnet overlapping, and helping structuring this readme file