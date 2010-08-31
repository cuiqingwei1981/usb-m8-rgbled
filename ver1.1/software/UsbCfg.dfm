object MForm: TMForm
  Left = 431
  Top = 306
  BorderStyle = bsDialog
  Caption = 'U-rgbLED'
  ClientHeight = 236
  ClientWidth = 456
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 88
    Top = 80
    Width = 65
    Height = 65
    Shape = stCircle
  end
  object Shape2: TShape
    Left = 312
    Top = 80
    Width = 65
    Height = 65
    Shape = stCircle
  end
  object Label1: TLabel
    Left = 32
    Top = 24
    Width = 169
    Height = 49
    AutoSize = False
    Caption = 'PC0(LED2)'
    Color = clCream
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 264
    Top = 24
    Width = 161
    Height = 49
    AutoSize = False
    Caption = 'PC1(LED1)'
    Color = clCream
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Button1: TButton
    Left = 40
    Top = 160
    Width = 161
    Height = 57
    Caption = #28857#20987#25105
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 264
    Top = 160
    Width = 161
    Height = 57
    Caption = #28857#20987#25105
    TabOrder = 1
    OnClick = Button2Click
  end
end
