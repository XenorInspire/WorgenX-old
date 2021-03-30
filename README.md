# WorgenX

A wordlist generator with several functionalities

# Requirements

### For Windows :

Install MinGW (gcc compilator for windows) at https://sourceforge.net/projects/mingw/
<br>
Then, add GCC in your environmental variables.

### For Linux :

`apt install gcc` (debian distribution)

`yum install gcc` (redhat distribution)

### For MacOS :

Follow these tutorials : 

1 : https://www.cyberciti.biz/faq/howto-apple-mac-os-x-install-gcc-compiler/

2 : https://mkyong.com/mac/how-to-install-gcc-compiler-on-mac-os-x/


# Installation

In a directory of your choice copy the repo :  
`git clone https://github.com/XenorInspire/KVM-Deploy-Tool.git`  

Move in the directory :  
`cd KVM-Deploy-Tool/`

### Compile WorgenX :

#### For Windows :

Go to the compilator folder and start WinCompilator.cmd.

#### For Linux/MacOS :

Go to the compilator folder :
`cd compilator/`

Make sure that the script has the right to be executed :  
`chmod +x UnixCompilator.sh`

Execute the compilator :  
`./UnixCompilator.sh`


# Start WorgenX

#### For Windows :

Exit the compilator folder and start *WorgenX.exe*.

#### For Linux/MacOS :

Exit the compilator folder and execute WorgenX :
`cd .. && ./WorgenX`


# Configuration

There is several parameters in the configuration file of WorgenX : 

Parameter | Description |
--- | --- |
MODE | There are 3 performance levels for WorgenX : 1 (LOW), 2 (MEDIUM) and 3 (HIGH). <br>More the value is high, more WorgenX use CPU performances.



# Mirrors

- <a href="https://github.com/XenorInspire/WorgenX">Github</a>
<br>
- <a href="https://gitlab.com/XenorInspire/WorgenX">Gitlab</a>
<br>

# Licence

This application is licensed under [GNU General Public License, Version 3.0].

[GNU General Public License, Version 3.0]:
 http://www.gnu.org/licenses/gpl-3.0-standalone.html
