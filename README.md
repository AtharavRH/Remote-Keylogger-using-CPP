# Remote-Keylogger-using-CPP
This is an basic remote keylogger which works silently under the hood and send the log through a TCP connection to the listner, You can listen them on the other side through netcat. Just save the file, and compile using an IDE to get a executable.

## To listen use-
 
nc.exe -lvp 5555                   <- For Windows    
nc -lvp 5555                       <- For Linux

