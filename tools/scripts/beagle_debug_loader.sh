# defines
TARGET_IP=192.168.7.2
GDB_SERVER_PORT=6233
EXE_NAME=sys_image
BEAGLE_EXE_PATH=/home/debian/Valkyrie/bin/sys_image
BEAGLE_EXE_FLDR=/home/debian/Valkyrie/bin

# Must be relative to the Task's CWD
HOST_EXE_PATH=./../../artifacts/last_build_version/sys_image

# kill gdbserver on target
echo "Removing running GDB server instances"
ssh debian@$TARGET_IP killall gdbserver
echo "Done"

# remove old executable on target
echo "Removing old executable on target device"
ssh debian@$TARGET_IP rm $BEAGLE_EXE_PATH

# copy over new executable
echo "Copying new executable"
scp $HOST_EXE_PATH debian@$TARGET_IP:$BEAGLE_EXE_FLDR

# start gdb on target (IS ONE LONG COMMAND)
echo "Starting GDB server"
ssh -n -f debian@$TARGET_IP "sh -c 'cd $BEAGLE_EXE_FLDR; nohup gdbserver $TARGET_IP:$GDB_SERVER_PORT $EXE_NAME > /dev/null 2>&1 &'"