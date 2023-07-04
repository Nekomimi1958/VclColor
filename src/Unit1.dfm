object VclColForm: TVclColForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'VCL Color'
  ClientHeight = 457
  ClientWidth = 588
  Color = clBtnFace
  Constraints.MaxWidth = 600
  Constraints.MinWidth = 600
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  ShowHint = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  OnShow = FormShow
  TextHeight = 17
  object RightPanel: TPanel
    Left = 388
    Top = 0
    Width = 200
    Height = 457
    Align = alRight
    BevelOuter = bvNone
    BorderWidth = 4
    TabOrder = 0
    ExplicitLeft = 384
    ExplicitHeight = 456
    object ValListBox: TListBox
      Left = 4
      Top = 221
      Width = 192
      Height = 232
      Hint = 'Double click to copy selected value'
      Style = lbOwnerDrawFixed
      Align = alClient
      ItemHeight = 18
      PopupMenu = PopupMenu2
      TabOrder = 0
      OnDblClick = ValListBoxDblClick
      OnDrawItem = ValListBoxDrawItem
      ExplicitHeight = 231
    end
    object ColPanel: TPanel
      Left = 4
      Top = 4
      Width = 192
      Height = 64
      Align = alTop
      BevelOuter = bvNone
      BorderWidth = 4
      Caption = 'Color Name'
      Color = clAppWorkSpace
      ParentBackground = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      StyleElements = [seBorder]
      OnClick = ColPanelClick
    end
    object CmpPanel: TPanel
      Tag = 1
      Left = 4
      Top = 68
      Width = 192
      Height = 64
      Align = alTop
      BevelOuter = bvNone
      Caption = 'Complementary'
      Color = clBtnShadow
      ParentBackground = False
      TabOrder = 2
      StyleElements = [seBorder]
      OnClick = ColPanelClick
    end
    object TriPanel: TPanel
      Left = 4
      Top = 157
      Width = 192
      Height = 64
      Align = alTop
      BevelOuter = bvNone
      PopupMenu = PopupMenu3
      TabOrder = 3
      object TriPanel1: TPanel
        Tag = 2
        Left = 0
        Top = 0
        Width = 64
        Height = 64
        Align = alLeft
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBtnText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        StyleElements = [seBorder]
        OnClick = ColPanelClick
      end
      object TriPanel3: TPanel
        Tag = 4
        Left = 128
        Top = 0
        Width = 64
        Height = 64
        Align = alClient
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBtnText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        StyleElements = [seBorder]
        OnClick = ColPanelClick
      end
      object TriPanel2: TPanel
        Tag = 3
        Left = 64
        Top = 0
        Width = 64
        Height = 64
        Align = alLeft
        BevelOuter = bvNone
        Color = clSilver
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBtnText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 1
        StyleElements = [seBorder]
        OnClick = ColPanelClick
      end
    end
    object TriComboBox: TComboBox
      Left = 4
      Top = 132
      Width = 192
      Height = 25
      Hint = 'Color Scheme'
      Align = alTop
      Style = csDropDownList
      PopupMenu = PopupMenu3
      TabOrder = 4
      OnClick = TriComboBoxClick
      Items.Strings = (
        'Triad'
        'Split Complementary'
        'Analogous'
        'Tetrad'
        'Contrast (S20)'
        'Contrast (L20)'
        'Custom Scheme')
    end
  end
  object LeftPanel: TPanel
    Left = 0
    Top = 0
    Width = 388
    Height = 457
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitWidth = 384
    ExplicitHeight = 456
    DesignSize = (
      388
      457)
    object TabControl1: TTabControl
      Left = 0
      Top = 29
      Width = 388
      Height = 428
      Align = alClient
      TabOrder = 0
      Tabs.Strings = (
        'VCL'
        'System'
        'Web Safe')
      TabIndex = 0
      TabWidth = 100
      OnChange = TabControl1Change
      ExplicitWidth = 384
      ExplicitHeight = 427
      object ColorListBox: TListBox
        Left = 4
        Top = 28
        Width = 380
        Height = 396
        Style = lbOwnerDrawFixed
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        OnClick = ColorListBoxClick
        OnDrawItem = ColorListBoxDrawItem
        ExplicitWidth = 376
        ExplicitHeight = 395
      end
    end
    object TopPanel: TPanel
      Left = 0
      Top = 0
      Width = 388
      Height = 29
      Align = alTop
      AutoSize = True
      BevelOuter = bvNone
      BorderWidth = 2
      TabOrder = 1
      ExplicitWidth = 384
      object Label4: TLabel
        Left = 14
        Top = 6
        Width = 28
        Height = 17
        Alignment = taRightJustify
        Caption = 'Filter'
      end
      object Label5: TLabel
        Left = 176
        Top = 6
        Width = 5
        Height = 17
        Caption = '-'
      end
      object FilterComboBox: TComboBox
        Left = 46
        Top = 2
        Width = 120
        Height = 25
        Style = csDropDownList
        TabOrder = 0
        OnClick = FilterComboBoxClick
        Items.Strings = (
          'All'
          'Monochrome'
          'Red'
          'Yellow'
          'Green'
          'Cyan'
          'Blue'
          'Magenta')
      end
      object L_ComboBox: TComboBox
        Left = 192
        Top = 2
        Width = 90
        Height = 25
        Style = csDropDownList
        TabOrder = 1
        OnClick = FilterComboBoxClick
        Items.Strings = (
          'All'
          'Light'
          'Medium'
          'Dark')
      end
    end
    object TargetPanel: TPanel
      Left = 350
      Top = 8
      Width = 34
      Height = 34
      Anchors = [akTop, akRight]
      BevelOuter = bvLowered
      TabOrder = 2
      ExplicitLeft = 346
      object Image1: TImage
        Left = 1
        Top = 1
        Width = 32
        Height = 32
        Hint = 'Spuit Tool'
        Align = alClient
        Picture.Data = {
          0954506E67496D61676589504E470D0A1A0A0000000D49484452000000200000
          00200804000000D973B27F000000097048597300000F6100000F6101A83FA769
          0000008B4944415478DAD595410AC0200C04BBFF7FF4F6248D71AD6E8442BD14
          9A99113C28AEC38582C368BA01E6ED3F0E70F883FF0428FF1A677018A096C367
          156004213A2BBD43CD0099612B90F58187A14B1667FA5B604B9F0F36F5D9685B
          D7434357634B1F0153CF88ADF750418F58499701EFAA6D28C37B61DD9368BA3C
          153B5078E870A63F81925CDE35AE1B04982F21D1680AE10000000049454E44AE
          426082}
        OnMouseDown = Image1MouseDown
        OnMouseUp = Image1MouseUp
        ExplicitLeft = 8
        ExplicitTop = 8
        ExplicitWidth = 105
        ExplicitHeight = 105
      end
    end
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 28
    Top = 75
  end
  object PopupMenu1: TPopupMenu
    Left = 120
    Top = 77
    object SelFontItem: TMenuItem
      Caption = 'Select List Font'
      OnClick = SelFontItemClick
    end
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    Left = 224
    Top = 77
  end
  object PopupMenu2: TPopupMenu
    Left = 424
    Top = 232
    object CopyValItem: TMenuItem
      Caption = 'Copy this value'
      ShortCut = 16451
      OnClick = CopyValItemClick
    end
    object CopyAllItem: TMenuItem
      Caption = 'Copy All'
      OnClick = CopyAllItemClick
    end
  end
  object PopupMenu3: TPopupMenu
    Left = 528
    Top = 165
    object CustomSetItem: TMenuItem
      Caption = 'Custom Scheme Setting...'
      OnClick = CustomSetItemClick
    end
  end
end
