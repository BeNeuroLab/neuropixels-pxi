/*
    ------------------------------------------------------------------
    This file is part of the Open Ephys GUI
    Copyright (C) 2020 Allen Institute for Brain Science and Open Ephys
    ------------------------------------------------------------------
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __SETTINGSINTERFACE_H_2C4C2D67__
#define __SETTINGSINTERFACE_H_2C4C2D67__

#include <VisualizerEditorHeaders.h>

#include "../NeuropixComponents.h"

class NeuropixThread;
class NeuropixEditor;
class NeuropixCanvas;

class SettingsInterface : public Component
{
public:
    SettingsInterface(Probe* probe_, NeuropixThread* thread_, NeuropixEditor* editor_, NeuropixCanvas* canvas_)
    {
        probe = probe_;
        editor = editor_;
        canvas = canvas_;
        thread = thread_;
    }
	~SettingsInterface() {}

	virtual void startAcquisition() = 0;
	virtual void stopAcquisition() = 0;

	virtual void applyProbeSettings(ProbeSettings, bool shouldUpdateProbe = true) = 0;

	virtual void saveParameters(XmlElement* xml) = 0;
	virtual void loadParameters(XmlElement* xml) = 0;

protected:

	NeuropixThread* thread;
	NeuropixEditor* editor;
	NeuropixCanvas* canvas;
	Probe* probe;
};

#endif //__SETTINGSINTERFACE_H_2C4C2D67__