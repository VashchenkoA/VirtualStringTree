object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 417
  ClientWidth = 831
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Status: TLabel
    Left = 680
    Top = 192
    Width = 31
    Height = 13
    Caption = 'Status'
  end
  object OutInfo: TLabel
    Left = 611
    Top = 232
    Width = 197
    Height = 13
  end
  object vst: TVirtualStringTree
    Left = 0
    Top = 0
    Width = 577
    Height = 417
    Align = alLeft
    Header.AutoSizeIndex = 0
    Header.Height = 28
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    OnGetText = vstGetText
    Columns = <
      item
        Position = 0
        Text = 'id'
        Width = 65
      end
      item
        Position = 1
        Text = 'url'
        Width = 144
      end
      item
        Position = 2
        Text = 'title'
        Width = 148
      end
      item
        Position = 3
        Text = 'visit_count'
        Width = 68
      end
      item
        Position = 4
        Text = 'last_visit_time'
        Width = 137
      end>
  end
  object Button1: TButton
    Left = 640
    Top = 41
    Width = 121
    Height = 49
    Caption = 'Open'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 640
    Top = 360
    Width = 121
    Height = 49
    Caption = 'Clear'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 640
    Top = 104
    Width = 121
    Height = 49
    Caption = 'Delete'
    TabOrder = 3
    OnClick = Button3Click
  end
end
