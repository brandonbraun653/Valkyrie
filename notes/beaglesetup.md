# Beagle Bone Setup
## Base Image
https://beagleboard.org/latest-images

At the time of writing, the Buster IoT image (AM3358 Debian 10.3) is being used.

## Networking Configuration
https://elementztechblog.wordpress.com/2014/12/22/sharing-internet-using-network-over-usb-in-beaglebone-black/

## Package Installation
1. Update/Upgrade the default distribution
2. Install gdbserver
3. Install psmisc     (Needed for the killall command)

## SSH Key Login
https://www.howtoforge.com/set-up-ssh-with-public-key-authentication-debian-etch

The important part here is to copy the generated .pub key into the "authorized_keys" file.

## Remote Debugging
https://medium.com/@karel.l.vermeiren/cross-architecture-remote-debugging-using-gdb-with-visual-studio-code-vscode-on-linux-c0572794b4ef
