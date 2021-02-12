# WorgenX

A wordlist generator with several functionalities

## Requirements

### For Windows :

Install MinGW (gcc compilator for windows) at http://www.mingw.org/

### For Linux :

`apt install gcc` (debian distribution)

`yum install gcc` (redhat distribution)


## Installation

In a directory of your choice copy the repo :  
`git clone https://github.com/XenorInspire/KVM-Deploy-Tool.git`  

Move in the directory :  
`cd KVM-Deploy-Tool/`

### Compile WorgenX :

#### For Windows :

Go to the compilator folder and start WinCompilator.cmd.

#### For Linux :

Go to the compilator folder :
`cd compilator/`

Make sure that the script has the right to be executed :  
`chmod +x UnixCompilator.sh`

Execute the compilator :  
`./UnixCompilator.sh`


## Start WorgenX

#### For Windows :

Exit the compilator folder and start *WorgenX.exe*.

#### For Linux :

Exit the compilator folder and execute WorgenX :
`cd .. && ./WorgenX`


## Configuration

There is several parameters in the configuration file of WorgenX : 

Parameter | Description |
--- | --- |
MODE | There are 3 performance levels for WorgenX : 1 (LOW), 2 (MEDIUM) and 3 (HIGH). More the value is high, more WorgenX use CPU performances.
