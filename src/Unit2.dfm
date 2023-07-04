object CustomDlg: TCustomDlg
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Custom Scheme'
  ClientHeight = 111
  ClientWidth = 198
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object RadioGroup1: TRadioGroup
    Left = 6
    Top = 6
    Width = 185
    Height = 49
    Caption = 'Mode'
    Columns = 3
    ItemIndex = 0
    Items.Strings = (
      'H'
      'S'
      'L')
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object TrackBar1: TTrackBar
    Left = 6
    Top = 72
    Width = 185
    Height = 33
    Max = 180
    Frequency = 30
    TabOrder = 1
    OnChange = TrackBar1Change
  end
end
