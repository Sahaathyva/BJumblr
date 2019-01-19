# B.SEQuencer
Repository: BSEQuencer

Description: Multi channel 16x16 MIDI step sequencer LV2 plugin

Installation
------------
Build your own binaries in the following three steps.

Step 1: Clone or download this repository.

Step 2: Install the development packages for x11, cairo, and lv2 if not done yet.

Step 3: Building and installing into the default lv2 directory (/usr/lib/lv2/) is easy. Simply call:
```
sudo make install
```
from the directory where you downloaded the repository files.

For installation into an alternative directory (e.g., /usr/local/lib/lv2), modify line 2 in the makefile.

Running
-------
After the installation Ardour, Carla, and any other LV2 host should automatically detect B.SEQuencer.

If jalv is installed, you can also call it
```
jalv.gtk https://www.jahnichen.de/plugins/lv2/BSEQuencer
```
to run it stand-alone and connect it to the JACK system.

Key features
------------
* Step sequencer with 16x16 matrix
* Control panel (in line 1 of the matrix)
* Autoplay or host / MIDI controlled playing
* Four output channels
* Output channels connectable with individual MIDI ports / channels

TODO
----
* Stability (Note: **This plugin is experimental, yet. Not for production!**)
* Playing direction




