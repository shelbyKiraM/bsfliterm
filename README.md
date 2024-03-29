# BSFlite - BS-Free AIM Client

(C) 2003-2010 by Claudio P. Leite
leitec (a) leitec (d) org
AIM: augaetis byrjun

This program includes NO WARRANTY. Please see the file COPYING for more 
details.

INTRODUCTION

 BSF is a very light and minimal client for AOL(R)'s Instant Messenger(TM)
service that works (or should work) under most varieties of UNIX. It 
features only the basics that every client should have, meaning
send/receive messages, add/delete buddies and view the buddy list. 

So far, the client is reported to work on following systems:

 * Linux - i386, Alpha, ARM. Several different kernel and libc versions.
 * NetBSD - tested on 1.4-3.0, several architectures.
 * FreeBSD - tested on 5.0-STABLE
 * OpenBSD - 3.3, 3.9, 4.0 on i386. (primary development platform)
 * Solaris - 5.7, 5.8 and 5.9, i86 and SPARC.
 * SunOS 4.1.4 - SPARC, does not compile out of the box, but works once
		 patched. (patch not yet included, use binary.
		 Alternatively, define uint32_t, uint16_t and uint8_t to
		 unsigned long/short/char, respectively.)
 * Windows - 95 through Vista.
 * MS-DOS - tested on a 386 (quite slow), acceptable on a 486/66.
 * Mac OS X - tested on 10.2-10.5, Intel and PPC
 * Plan 9 - tested only on x86
   (replace ~/.bsflite with $home/lib/bsflite for configuration files)

 I've successfully compiled with gcc, 8c/pcc, Sun CC, Intel CC,
 and Watcom C (Win32).

My philosophy in regards to portability is that if it doesn't compile, 
it's my fault, not yours. If you have a system that hasn't been tested 
yet, please send me a note. If bsflite doesn't compile on your system, 
definitely do send me a note. It's probably a simple fix. I write my code 
to be as portable as possible, using standard types and calls (and porting
regularly exposes errors I've made).

INSTALLING

 * FROM SOURCE

 Edit the Makefile to add any additional options.
 Edit bsf.h, scroll to the bottom to change formats, including outgoing
 IM formats.

 To compile, do the following:
 (% represents a user prompt, # represents a root prompt.)

 % make
 % su (optional, the binary may be installed anywhere.)
 # cp bsflite /usr/local/bin (or any other directory you wish.)
 # exit

 If you encounter errors about uintXX_t, try adding

 #include <stdint.h>

 to imcomm/imcomm.h, after the other #include's.

 Solaris users will have to add "-lsocket -lnsl" to LIBS in the Makefile.

 * FROM BINARY

 To install from a binary, do the following:

 % gunzip bsflite-binary-name.gz
 % mv bsflite-binary-name bsflite
 % chmod 755 bsflite
 % su (optional, the binary may be installed anywhere.)
 # cp bsflite /usr/local/bin
 # exit

 You should now be able to run the bsflite program.

USAGE

 If you're skimming, please read the "Using with screen" section.

 BSFlite supports a small configuration file. An example file is included
 in the archive. To set up a minimal file, enter the following:

 % mkdir ~/.bsflite
 % chmod 700 ~/.bsflite
 % echo "username myscreenname" > ~/.bsflite/config

 If you'd like to have your password stored, run the following:

 % echo "password mypassword" >> ~/.bsflite/config

 Custom HTML profiles are read from ~/.bsflite/profile.
 Buddy icons are read from ~/.bsflite/icons. Icons may be in GIF and JPEG
 format (as far as I know).

 Now just type bsflite to start and connect. If you did not make a config
file, you will be prompted for username and password.

 Type help or h at the prompt to see commands. It's best not to put a 
space between the commands (it might be a little buggy otherwise, since 
that's not the way I do it). For example:

 :: mmybuddy this is a test

 instead of

 :: m mybuddy this is a test

 If you prefer that way and find a bug, please notify me. Please also 
notice that you cannot put a space in the person's screen name.

 To facilitate the m command, you can type the first few letters of 
someone's screen name (provided they are in your buddy list) and press TAB 
to auto-complete the name. Please see the bugs section later for some 
current problems.

USING WITHIN SCREEN

 I strongly recommend the use of screen, the console windowing system. 
With screen, you can keep this program running even while you're logged 
off the system and reattach once you're back. Since bsflite stores 
incoming messages you missed and supports away messages, this is a 
very convenient feature. Also, if you're connecting to a system 
remotely over SSH or telnet and your connection is dropped, screen 
keeps your session running. Check with your sysadmin if you're on a 
multiuser system to see if screen is allowed.

BUDDY LISTS

 As of version 0.80, imcomm writes your buddy lists to the server, like
the official client. So, the ~/.bsflite/buddies file is now unnecessary.
Please delete the file after running the program once if you have one,
because your buddies will already have been added to the server.

RATE LIMIT WARNINGS

 NOTE: Rate limit updates are completely broken right now (as of 0.84).
       This section should be ignored for the time being.

 The confession: IMComm does not respect rate limits just yet.

 The workaround, sort of: BSFlite displays a warning on the prompt to let you
know you are sending packets too quickly.

 If you're being warned, your prompt will be:

 <!> [randomperson] :: 

 This will go away in 30 seconds unless you're warned again. If you exceed the
limit, the server will begin to ignore you. At this point, your prompt will
be:

 <!!> [randomperson] ::

 This will go away in some time (haven't figured out how much just yet), but
for some reason the server doesn't tell us until you sent out a packet that
isn't ignored. It's quirky; the easiest way to avoid this is to be gentle.

 NOTE: Requesting several peoples' profiles will most likely cause a rate
limit warning. This is due to the fact that request makes two calls, one for a
profile request and one for an away message request. Since these are sent
without respect to rate limits, they are quite quick.

MISCELLANY

 To update your profile, edit ~/.bsflite/profile then run:

 % kill -USR1 <bsflite PID> (use ps to get the PID)
 or (for Linux)
 % killall -USR1 bsflite

 If you'd like to create a set of away messages (see the G command),
 create a file ~/.bsflite/awaymessages, with one message per line.
 You may use HTML formatting in each line, but make sure there is no
 line break in a message, because that'll indicate a new message.

 Type G to see which numbers are assigned to each message, and type
 G<num> to set that away message. One-time messages can still be set
 with the g<message> command.

LOGGING

 By default, BSF logs all AIM conversations in a directory called .bsflite/log
in your home directory. This directory is chmod 700, meaning only you can 
read it. This will be a compile-time option later (I really don't like 
configuration files, so all features will be compile-time!)

LICENSING (NOTE: I am not a lawyer.)

 BSF is licensed under the BSD License. Please see the COPYING file 
in the main bsf directory. The IMComm library, included in the main source
package, is also licensed under the same terms.
 This project contains no code from AOL, and was developed without the use
of reverse engineering of any AOL product. Instant Messenger is a trademark
of AOL. 

CONTACT

 BSF releases may be obtained from http://bsflite.sf.net/ , and I may be 
reached at leitec (a) leitec (d) org, or over AIM, "augaetis byrjun."

 Please send me a note if you like bsflite! Hearing from users encourages
me to keep developing the program.

 Also, I like receiving postcards, so if you'd like to send one to show your
appreciation, you may at:

 Claudio Leite
 1305 Linden Court NE
 Washington, DC 20002
 USA

 Thanks and enjoy!
