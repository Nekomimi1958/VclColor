//----------------------------------------------------------------------//
// VclColor																//
//----------------------------------------------------------------------//
USEFORM("Unit1.cpp", VclColForm);
USEFORM("Unit2.cpp", CustomDlg);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try {
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TVclColForm), &VclColForm);
		Application->CreateForm(__classid(TCustomDlg), &CustomDlg);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
