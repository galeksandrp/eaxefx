EAX OpenAL Extension
====================


Contents
========

1. Overview
2. Minimum requirements
3. Patches
4. Supported drivers
5. Driver file name convention
6. Missing features  
   6.1 Bypassed  
   6.2 Not supported
7. Known issues
8. Usage
9. Compiling requirements
10. FAQ
11. Third party use
12. Disclaimer


1 - Overview
============

The project enables EAX OpenAL Extension for systems without appropriate hardware.

OpenAL wrapper implements EAX calls with Effects Extension by using underlying OpenAL driver.


2 - Minimum requirements
========================

Operating system:
- Windows XP with Service Pack 3


3 - Patches
===========

Several runtime patches are embeded into the wrapper to fix EAX issues.

Separate application `eaxefx_app_patcher.exe` is available for offline patching.

Resolved issues:
- Doom 3 (2004) [visual twitch bug](http://www.pcgamingwiki.com/wiki/Doom_3#Visual_twitch_bug_with_OpenAL.2FEAX).
- Quake 4 (2005) source occlusion out of range.
- Prey (2006) source occlusion out of range.  
  Only runtime patching is supported for Steam version.


4 - Supported drivers
=====================

- [OpenAL Soft](http://openal-soft.org)

Notes:
- Driver is not included into release package.


5 - Driver file name convention
===============================

The driver should be named with one of the following names:
- `eaxefx_driver.dll`
- `dsoal-aldrv.dll`
- `soft_oal.dll`

The wrapper tries to load a driver in the order specified above.


6 - Missing features
====================


6.1 - Bypassed features
=======================

Context:
- HF Reference (EAX 4.0/5.0)
- Macro FX Factor (EAX 5.0)
- Speaker configuration (EAX 5.0)

Source:
- Speaker levels (EAX 5.0)


6.2 - Not supported
===================

General:
- X-RAM


7 - Known issues
================

- OpenAL Soft official binaries v1.20.x may cause a crash upon exiting the application.

- EAX effects are missing in Unreal Tournament 2004 with [X-Fi Sound Blaster patch](http://www.unrealcentral.com/ut2004-v3369-x-fi-sound-blaster-patch/).


8 - Usage
=========

Terminology:
- `DIR` - the directory with application's main executable.

Steps:
1. Backup (if necessary) `OpenAL32.dll` in the `DIR`.
2. Extract the release package into some directory.
3. Copy extracted `OpenAL32.dll` into the `DIR`.
4. Put properly named driver into the `DIR`.
5. Enable appropriate EAX options in the application and restart it if necessary.


9 - Compiling requirements
==========================

Common:
- Windows 32-bit build target.

Minimum:
- CMake v3.8.2
- C++17 compatible compiler.


10 - FAQ
========

Q: There is a subtle difference in audio when using the wrapper.

A: Search driver's documentation about amplifying EAX properties.  
In case of OpenAL Soft it's [`boost` option in `reverb` section](http://github.com/kcat/openal-soft/blob/master/alsoftrc.sample).  
Example of `alsoft.ini`:
```
[reverb]
boost = 8
```


11 - Third party use
====================

* [OpenAL Soft](http://openal-soft.org/)  
  See file `eaxefx_openal_soft_license.txt` for license information.  


12 - Disclaimer
===============

Copyright (c) 2020-2021 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
OR OTHER DEALINGS IN THE SOFTWARE.
