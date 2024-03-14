# WorgenX

A wordlist generator with several functionalities.

> [!NOTE] 
> This project isn't maintained anymore, please check the <a href="https://github.com/XenorInspire/WorgenX">new version of WorgenX</a>, fully rewritten in Rust with major improvements.

# Requirements

### For Windows :

Install MinGW (gcc compilator for windows) at https://sourceforge.net/projects/mingw/
<br>
Then, add GCC in your environment variables.

### For Linux :

`apt install gcc -y` (debian distribution)

`dnf install gcc -y` (redhat distribution)

### For MacOS :

Follow these tutorials : 

1 : https://www.cyberciti.biz/faq/howto-apple-mac-os-x-install-gcc-compiler/

2 : https://mkyong.com/mac/how-to-install-gcc-compiler-on-mac-os-x/


# Installation

In a directory of your choice copy the repo :  
`git clone https://github.com/XenorInspire/WorgenX.git`<br> 
`git clone https://gitlab.com/XenorInspire/WorgenX.git`<br> 
<br> 
Move in the directory :  
`cd WorgenX/`

### Compile WorgenX :

#### For Windows :

Go to the compilator folder and start *WinCompilator.cmd*.

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
- <a href="https://gitlab.com/XenorInspire/WorgenX">Gitlab</a>

# Licence

This application is licensed under [GNU General Public License, Version 3.0].

[GNU General Public License, Version 3.0]:
 http://www.gnu.org/licenses/gpl-3.0-standalone.html
