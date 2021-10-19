# minitalk
1) First you need to write "server" programm, which will print it's PID and wait for signals.
2) Your "client" programm must get that PID as argument and some message. "client" programm must send it to "server" programm just using SIGUSR1 and SIGUSR2 signals.
3) If you will GOOGLE "How to send message with signals ?" You will find NOTHING. You just can't send a characters with signals.
4) But we are smart guys and we never give up. So... How to do it ?
5) You must send your message BIT BY BIT.
6) Get a character from your message, every char has its ASCII code and it's BINARY CODE. For example a = 97 = 01100001
7) Use Binary operations (<< and &). Use "&" operator to uderstand what is your first bit 0 or 1, if it's 1, I will send SIGUSR1 else SIGUSR2.
8) In "server" programm I will check do I get SIGUSR1 or SIGUSR2 and then I will have my character. Using ft_atoi_base function I have it in decimal and will print it.

Thats it. If you have some questions ask me. arsen.aramyan2001@gmail.com
