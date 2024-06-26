#pragma once

#include <wx/wx.h>

#include "CustomButton.h"
#include "TextBox.h"
#include "SVGPanel.h"
#include "wxImagePanel.h"
#include "AppSetting.h"

class SignUpPanel : public wxWindow
{
public:
public:
	SignUpPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, AppSetting* appSetting);

	wxStaticText* get_signUpButton();
	wxStaticText* get_alreadyRegisteredButton();

	wxString get_identtity();
	wxString get_pass();
	wxString get_confirmPass();

	void clear_fields();

	/* Diese Funktion pr�ft, ob eine Zeichenkette (das Passwort) sicher ist, 
	d.h. sie enth�lt mindestens einen Gro�buchstaben, einen Kleinbuchstaben, 
	eine Zahl, ein Sonderzeichen und hat eine L�nge von mindestens 8.*/
	bool isPasswordStrong();

private:
	TextBox* identityBox = nullptr;
	TextBox* passwordBox = nullptr;
	TextBox* shownPasswordBox = nullptr;
	TextBox* confirmPasswordBox = nullptr;
	TextBox* confirmShownPasswordBox = nullptr;

	SVGPanel* openEyeSVG;
	SVGPanel* closeEyeSVG;
	SVGPanel* confirmOpenEyeSVG;
	SVGPanel* confirmCloseEyeSVG;

	CustomButton* signUpButton;
	CustomButton* alreadyRegisteredButton;

	wxSizer* passwordSizer;
	wxSizer* confirmPasswordSizer;

	void onPasswordBoxChange(wxCommandEvent& event);
	void onShownPasswordBoxChange(wxCommandEvent& event);
	void onConfirmPasswordBoxChange(wxCommandEvent& event);
	void onConfirmShownPasswordBoxChange(wxCommandEvent& event);

	void showPassword(wxMouseEvent& event);
	void hidePassword(wxMouseEvent& event);
};

