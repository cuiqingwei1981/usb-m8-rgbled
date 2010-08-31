object mForm: TmForm
  Left = 321
  Top = 190
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'U-rgbLED'
  ClientHeight = 303
  ClientWidth = 519
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020040000000000E80200001600000028000000200000004000
    0000010004000000000000020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000088
    8888000000000000000000000000888888888888888800000000000000000000
    00000088888888800000000000000000DDDDD00000088888800000000000DDDD
    DDDDDDDDDD0000888880000000000000000008DDDDDDD0000888800000000000
    0000000008DDDDDDD0088800000000000000000000008DCCCDD0888000000000
    000000000000000CCCC408880000008880000000000000000CCCC48880000811
    1800000000000000000CCC488800099918000000000000000000CCC488800099
    918000000000000000000CCC488000009980000000000000000008CCC4888000
    0988000000000000000002CCC48818000001800000000000000082ACCC489180
    8089188000000000000082AAAC480098181991188800000000082AAAAC480009
    99919991111888888882AAAAAAC800011999999999911111332AAAAAAAC00001
    999999999999999BBBAAAAAAAAC0881999999999999999BBBBBBBAAAAC009999
    9999999999999999BBBBBBBAAC000099999999999999999BBBBBBBBBA0000000
    99999999999999BBBBBBBBBA00000000009999999999999BBBBBBAA000000000
    0000999999999999BB990000000000000000000999999999990000000000FFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFC0FFFFFF0000FFFFFFC01FFFF07E07FF0003
    C1FFFF80787FFFF8063FFFFF011FFFFFE08FC7FFF80783FFFE0383FFFF01C1FF
    FF81F1FFFF8078FFFF803E7FFF00141FFF00C003FE00E0000000E0000001E000
    00010000000300000003C0000007F000000FFC00001FFF0000FFFFE003FF}
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object AAFadeText: TAAFadeText
    Left = 240
    Top = 24
    Width = 265
    Height = 33
    ParentEffect.ParentColor = False
    ParentEffect.ParentFont = False
    Fonts = <
      item
        Name = 'Title1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = #40657#20307
        Font.Style = [fsBold]
        Effect.Shadow.Enabled = True
      end
      item
        Name = 'Title2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -12
        Font.Name = #40657#20307
        Font.Style = [fsBold]
        Effect.Shadow.Enabled = True
        Effect.Shadow.OffsetX = 1
        Effect.Shadow.OffsetY = 1
      end
      item
        Name = 'Title3'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -15
        Font.Name = #26999#20307'_GB2312'
        Font.Style = []
        Effect.Shadow.Enabled = True
      end
      item
        Name = 'Text1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #26999#20307'_GB2312'
        Font.Style = []
        Effect.Shadow.OffsetX = 1
        Effect.Shadow.OffsetY = 1
      end
      item
        Name = 'Text2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clTeal
        Font.Height = -11
        Font.Name = #26999#20307'_GB2312'
        Font.Style = []
        Effect.Shadow.Enabled = True
        Effect.Shadow.OffsetX = 1
        Effect.Shadow.OffsetY = 1
      end
      item
        Name = 'Title4'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -29
        Font.Name = #38582#20070
        Font.Style = []
        Effect.Shadow.Enabled = True
        Effect.Gradual.Enabled = True
        Effect.Gradual.StartColor = 16720384
        Effect.Gradual.EndColor = 2232575
        Effect.Blur = 50
        Effect.Outline = True
      end
      item
        Name = 'Text3'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -15
        Font.Name = #38582#20070
        Font.Style = []
        Effect.Shadow.Enabled = True
        Effect.Shadow.OffsetX = 1
        Effect.Shadow.OffsetY = 1
        Effect.Gradual.Enabled = True
        Effect.Gradual.Style = gsTopToBottom
        Effect.Gradual.StartColor = 13404177
        Effect.Gradual.EndColor = 16720554
      end>
    Labels = <
      item
        Name = 'Left'
        Style = lsLeftJustify
      end
      item
        Name = 'Center'
        Style = lsCenter
      end
      item
        Name = 'Right'
        Style = lsRightJustify
      end
      item
        Name = 'Owner'
        Style = lsRegOwner
      end
      item
        Name = 'Organization'
        Style = lsRegOrganization
      end
      item
        Name = 'AppTitle'
        Style = lsAppTitle
      end
      item
        Name = 'Date'
        Style = lsDate
      end
      item
        Name = 'Time'
        Style = lsTime
      end>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Text.Lines.Strings = (
      '<Title1><Center>rgbLED Config Tool v1.0'
      ''
      '<Title2>'#29256#26435#22768#26126
      '<Text1>'#26412#36719#20214#20026#20813#36153#36719#20214
      #20256#25773#35831#27880#26126#20316#32773#21450#20986#22788
      #22914#21457#29616#38169#35823#35831#19982#20316#32773#32852#31995
      ''
      '<Title2>'#24320#21457#32773
      '<Text1>'#20316#32773#65306#23828#24198#20255
      'Email'#65306'qingwei_cui@163.com'
      'http://shop33642563.taobao.com/'
      #23567#23828' '#30005#23376#35774#35745#21046#20316#31995#21015#20043#19968)
    Text.FontEffect.Shadow.Enabled = True
    Text.FontEffect.Gradual.Enabled = True
    Text.FontEffect.Gradual.Style = gsTopToBottom
    Text.BackColor = clBtnFace
  end
  object rgbGroup: TGroupBox
    Left = 16
    Top = 16
    Width = 217
    Height = 273
    Caption = #19977#22522#33394#35843#21046
    TabOrder = 0
    object Rl: TLabel
      Left = 20
      Top = 241
      Width = 39
      Height = 24
      AutoSize = False
      Caption = 'Red'
      Color = clBtnFace
      Font.Charset = ANSI_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object Gl: TLabel
      Left = 79
      Top = 241
      Width = 59
      Height = 24
      AutoSize = False
      Caption = 'Green'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object Bl: TLabel
      Left = 160
      Top = 241
      Width = 43
      Height = 24
      AutoSize = False
      Caption = 'Blue'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object R: TiSlider
      Left = 16
      Top = 24
      Width = 57
      Height = 217
      PositionMax = 255
      PointerIndicatorInactiveColor = clRed
      PointerIndicatorActiveColor = clBlack
      KeyArrowStepSize = 1
      KeyPageStepSize = 10
      MouseWheelStepSize = 1
      TickMajorCount = 7
      TickMinorCount = 5
      TickLabelFont.Charset = DEFAULT_CHARSET
      TickLabelFont.Color = clWindowText
      TickLabelFont.Height = -11
      TickLabelFont.Name = 'MS Sans Serif'
      TickLabelFont.Style = []
      TabOrder = 0
      OnPositionChangeFinished = rgbPositionChangeFinished
      PositionMax_2 = 255
      KeyArrowStepSize_2 = 1
      KeyPageStepSize_2 = 10
    end
    object G: TiSlider
      Left = 80
      Top = 24
      Width = 57
      Height = 217
      PositionMax = 255
      PointerIndicatorInactiveColor = clLime
      PointerIndicatorActiveColor = clBlack
      KeyArrowStepSize = 1
      KeyPageStepSize = 10
      MouseWheelStepSize = 1
      TickMajorCount = 7
      TickLabelFont.Charset = DEFAULT_CHARSET
      TickLabelFont.Color = clWindowText
      TickLabelFont.Height = -11
      TickLabelFont.Name = 'MS Sans Serif'
      TickLabelFont.Style = []
      TabOrder = 1
      OnPositionChangeFinished = rgbPositionChangeFinished
      PositionMax_2 = 255
      KeyArrowStepSize_2 = 1
      KeyPageStepSize_2 = 10
    end
    object B: TiSlider
      Left = 144
      Top = 24
      Width = 57
      Height = 217
      PositionMax = 255
      PointerIndicatorInactiveColor = clBlue
      PointerIndicatorActiveColor = clBlack
      KeyArrowStepSize = 1
      KeyPageStepSize = 10
      MouseWheelStepSize = 1
      TickMajorCount = 7
      TickLabelFont.Charset = DEFAULT_CHARSET
      TickLabelFont.Color = clWindowText
      TickLabelFont.Height = -11
      TickLabelFont.Name = 'MS Sans Serif'
      TickLabelFont.Style = []
      TabOrder = 2
      OnPositionChangeFinished = rgbPositionChangeFinished
      PositionMax_2 = 255
      KeyArrowStepSize_2 = 1
      KeyPageStepSize_2 = 10
    end
  end
  object hsvGroup: TGroupBox
    Left = 240
    Top = 64
    Width = 265
    Height = 225
    Caption = #33394#24425#35843#21046
    TabOrder = 1
    object Hl: TLabel
      Left = 8
      Top = 40
      Width = 42
      Height = 14
      Caption = #33394'  '#35843
      Font.Charset = ANSI_CHARSET
      Font.Color = clFuchsia
      Font.Height = -14
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Sl: TLabel
      Left = 8
      Top = 104
      Width = 42
      Height = 14
      Caption = #39281#21644#24230
      Font.Charset = ANSI_CHARSET
      Font.Color = clOlive
      Font.Height = -14
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Vl: TLabel
      Left = 8
      Top = 176
      Width = 42
      Height = 14
      Caption = #20142'  '#24230
      Font.Charset = ANSI_CHARSET
      Font.Color = clTeal
      Font.Height = -14
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object H: TiSlider
      Left = 56
      Top = 24
      Width = 200
      Height = 57
      PositionMax = 255
      PointerIndicatorInactiveColor = 8388863
      PointerIndicatorActiveColor = clBlack
      KeyArrowStepSize = 1
      KeyPageStepSize = 10
      MouseWheelStepSize = 1
      Orientation = ioHorizontal
      TickLabelFont.Charset = DEFAULT_CHARSET
      TickLabelFont.Color = clWindowText
      TickLabelFont.Height = -11
      TickLabelFont.Name = 'MS Sans Serif'
      TickLabelFont.Style = []
      TabOrder = 0
      OnPositionChangeFinished = hsvPositionChangeFinished
      PositionMax_2 = 255
      KeyArrowStepSize_2 = 1
      KeyPageStepSize_2 = 10
    end
    object S: TiSlider
      Left = 56
      Top = 88
      Width = 200
      Height = 57
      PositionMax = 255
      PointerIndicatorInactiveColor = 8454143
      PointerIndicatorActiveColor = clBlack
      KeyArrowStepSize = 1
      KeyPageStepSize = 10
      MouseWheelStepSize = 1
      Orientation = ioHorizontal
      TickLabelFont.Charset = DEFAULT_CHARSET
      TickLabelFont.Color = clWindowText
      TickLabelFont.Height = -11
      TickLabelFont.Name = 'MS Sans Serif'
      TickLabelFont.Style = []
      TabOrder = 1
      OnPositionChangeFinished = hsvPositionChangeFinished
      PositionMax_2 = 255
      KeyArrowStepSize_2 = 1
      KeyPageStepSize_2 = 10
    end
    object V: TiSlider
      Left = 56
      Top = 152
      Width = 200
      Height = 57
      PositionMax = 255
      PointerIndicatorInactiveColor = clAqua
      PointerIndicatorActiveColor = clBlack
      KeyArrowStepSize = 1
      KeyPageStepSize = 10
      MouseWheelStepSize = 1
      Orientation = ioHorizontal
      TickLabelFont.Charset = DEFAULT_CHARSET
      TickLabelFont.Color = clWindowText
      TickLabelFont.Height = -11
      TickLabelFont.Name = 'MS Sans Serif'
      TickLabelFont.Style = []
      TabOrder = 2
      OnPositionChangeFinished = hsvPositionChangeFinished
      PositionMax_2 = 255
      KeyArrowStepSize_2 = 1
      KeyPageStepSize_2 = 10
    end
  end
end
