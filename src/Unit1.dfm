object VclColForm: TVclColForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'VCL Color'
  ClientHeight = 457
  ClientWidth = 584
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
    Left = 384
    Top = 0
    Width = 200
    Height = 457
    Align = alRight
    BevelOuter = bvNone
    BorderWidth = 4
    TabOrder = 0
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
    Width = 384
    Height = 457
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    DesignSize = (
      384
      457)
    object TabControl1: TTabControl
      Left = 0
      Top = 29
      Width = 384
      Height = 428
      Align = alClient
      TabOrder = 0
      Tabs.Strings = (
        'VCL'
        'System'
        'Style'
        'Web Safe')
      TabIndex = 0
      TabWidth = 82
      OnChange = TabControl1Change
      OnChanging = TabControl1Changing
      object ColorListBox: TListBox
        Left = 4
        Top = 28
        Width = 376
        Height = 396
        Style = lbOwnerDrawFixed
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        OnClick = ColorListBoxClick
        OnDrawItem = ColorListBoxDrawItem
        ExplicitLeft = 1
        ExplicitTop = 1
        ExplicitWidth = 32
        ExplicitHeight = 32
      end
    end
    object TopPanel: TPanel
      Left = 0
      Top = 0
      Width = 384
      Height = 29
      Align = alTop
      AutoSize = True
      BevelOuter = bvNone
      BorderWidth = 2
      TabOrder = 1
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
      object VirtualImage1: TVirtualImage
        Left = 2
        Top = 2
        Width = 32
        Height = 32
        ImageCollection = ImageCollection1
        ImageWidth = 0
        ImageHeight = 0
        ImageIndex = 0
        ImageName = 'SPUIT_TOOL'
        OnMouseDown = VirtualImage1MouseDown
        OnMouseUp = VirtualImage1MouseUp
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
    AutoHotkeys = maManual
    Left = 120
    Top = 77
    object SelFontItem: TMenuItem
      Caption = 'Select List Font'
      OnClick = SelFontItemClick
    end
    object Sep_1: TMenuItem
      Caption = '-'
    end
    object StyleItem: TMenuItem
      Caption = 'Style'
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
  object ImageCollection1: TImageCollection
    Images = <
      item
        Name = 'SPUIT_TOOL'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000020000000200804000000D973B2
              7F000000097048597300000F6100000F6101A83FA7690000009A494441544889
              BD95510E8030084399F1FE57C69F6DC280A530239FD2D776263AA2C369058625
              9935E035FE2A34583DCAF94444EDB8C16F47B0E53BFD53032FBF933796C33249
              852247600E4A60063CD0F03D6278971AFDDE40E3AE766700E03B03088F17201E
              AD60DC5F26706F9DC2AD2089AF9234AE45055CCA4AB8FB3165F0D760C6E7F021
              66F3041EFD472A5C744DE457EEC9D9A0047F320F25882730C67763F200000000
              49454E44AE426082}
          end>
      end>
    Left = 424
    Top = 312
  end
end
