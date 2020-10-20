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

### Compile and execute the compilator :

#### For Windows :

Go to the compilator folder and execute this command :
`gcc WinxCompilator.c -o WinCompilator.exe`

Execute the compilator :  
`./WinCompilator.exe`

#### For Linux :

Go to the compilator folder and compile the compilator :
`cd compilator/ && gcc UnixCompilator.c -o UnixCompilator`

Make sure that the script has the right to be executed :  
`chmod +x UnixCompilator`

Execute the compilator :  
`./UnixCompilator`


## Start WorgenX

#### For Windows :

Exit the compilator folder and execute WorgenX :

`./WorgenX.exe`

#### For Linux :

Exit the compilator folder and execute WorgenX :

`cd .. && ./WorgenX`
