Klipper install tool [https://docs.mainsail.xyz/setup/kiauh]
------------------------------------------------------------

Basis: dietpi

Installation
------------
login als dietpi

$ cd ~
$ sudo apt install git -y
$ git clone https://github.com/th33xitus/kiauh.git
$ ./kiauh/kiauh.sh

install klipper, moonraker, mainsail

$ cd ~/klipper
$ make menuconfig
$ make

$ ls /dev/serial/by-id/*
device kopieren, braucht man später

out/klipper.bin auf eine sd card kopieren und in firmware.bin umbenennen
Das Board mit der eingelegten sd-card starten

hier die passende cfg Datei für den Drucker suchen
https://github.com/KevinOConnor/klipper/tree/master/config

im Webinterface:
Settings > Machine > printer.cfg

Den Inhalt der runtergeladenen Datei einpflegen. Aufpassen, dass [virtual_sdcard] erhalten bleibt

Korrektur der Berechtigungen für die serielle Schnittstelle für den Benutzer, unter dem klipper läuft:
$ sudo usermod -a -G dialout dietpi

Nach einem Neustart funktioniert das Druckerdisplay und das Webinterface

Kalibrierung
============

Extruder
--------
https://github.com/KevinOConnor/klipper/blob/master/docs/Rotation_Distance.md#calibrating-rotation_distance-on-extruders

Korrekturen
===========
printer.cfg > [extruder]
max_extrude_cross_section: 100

Wenn die Slicer API nicht mehr funktioniert, das hier eintragen:
moonraker.conf > [octoprint_compat]
