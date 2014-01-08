object Form5: TForm5
  Left = 320
  Top = 200
  Caption = 'Filters'
  ClientHeight = 487
  ClientWidth = 719
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 719
    Height = 487
    Align = alClient
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 717
      Height = 485
      ActivePage = TabSheet5
      Align = alClient
      TabOrder = 0
      object TabSheet5: TTabSheet
        Caption = 'Control Panel'
        ImageIndex = 4
        object Panel1: TPanel
          Left = 0
          Top = 384
          Width = 709
          Height = 73
          Align = alBottom
          TabOrder = 0
          object Button1: TButton
            Left = 295
            Top = 16
            Width = 96
            Height = 33
            Caption = 'Load'
            TabOrder = 0
            OnClick = Button1Click
          end
          object DriveComboBox1: TDriveComboBox
            Left = 0
            Top = 22
            Width = 145
            Height = 19
            DirList = DirectoryListBox1
            TabOrder = 1
          end
        end
        object Panel3: TPanel
          Left = 0
          Top = 0
          Width = 391
          Height = 384
          Align = alLeft
          TabOrder = 1
          object DirectoryListBox1: TDirectoryListBox
            Left = 1
            Top = 1
            Width = 389
            Height = 382
            Align = alClient
            FileList = FileListBox1
            TabOrder = 0
          end
        end
        object Panel4: TPanel
          Left = 391
          Top = 0
          Width = 318
          Height = 384
          Align = alClient
          TabOrder = 2
          object FileListBox1: TFileListBox
            Left = 1
            Top = 1
            Width = 316
            Height = 382
            Align = alClient
            ItemHeight = 13
            TabOrder = 0
          end
        end
      end
      object TabSheet1: TTabSheet
        Caption = 'Filters'
        DesignSize = (
          709
          457)
        object GroupBox1: TGroupBox
          Left = 19
          Top = 3
          Width = 246
          Height = 63
          Caption = 'Window size'
          TabOrder = 0
          object ComboBox1: TComboBox
            Left = 16
            Top = 23
            Width = 65
            Height = 21
            TabOrder = 0
            Text = '3'
            Items.Strings = (
              '3'
              '4'
              '5'
              '6'
              '7'
              '8'
              '9'
              '10'
              '11'
              '12'
              '13'
              '14'
              '15'
              '16'
              '17'
              '18'
              '19'
              '20')
          end
          object Button4: TButton
            Left = 104
            Top = 21
            Width = 75
            Height = 25
            Caption = 'Generate'
            TabOrder = 1
            OnClick = Button4Click
          end
        end
        object GroupBox2: TGroupBox
          Left = 451
          Top = 3
          Width = 235
          Height = 63
          Anchors = [akTop, akRight]
          Caption = 'Use filter:'
          TabOrder = 1
          object Button2: TButton
            Left = 31
            Top = 23
            Width = 74
            Height = 26
            Caption = 'Window'
            TabOrder = 0
            OnClick = Button2Click
          end
          object Button3: TButton
            Left = 144
            Top = 23
            Width = 75
            Height = 25
            Caption = 'Median'
            TabOrder = 1
            OnClick = Button3Click
          end
        end
        object GroupBox3: TGroupBox
          Left = 19
          Top = 128
          Width = 667
          Height = 313
          Caption = 'Window parameters'
          TabOrder = 2
        end
        object GroupBox4: TGroupBox
          Left = 451
          Top = 68
          Width = 235
          Height = 54
          Caption = 'Normalization factor'
          TabOrder = 3
          object ComboBox3: TComboBox
            Left = 15
            Top = 23
            Width = 98
            Height = 21
            TabOrder = 0
            Text = '9'
          end
          object CheckBox1: TCheckBox
            Left = 139
            Top = 25
            Width = 14
            Height = 17
            TabOrder = 1
          end
        end
        object GroupBox9: TGroupBox
          Left = 19
          Top = 72
          Width = 246
          Height = 50
          Caption = 'Panel'
          TabOrder = 4
          object Label9: TLabel
            Left = 8
            Top = 24
            Width = 51
            Height = 13
            Caption = 'Threshold:'
          end
          object Label10: TLabel
            Left = 65
            Top = 24
            Width = 24
            Height = 13
            Caption = 'none'
          end
          object TrackBar3: TTrackBar
            Left = 93
            Top = 19
            Width = 150
            Height = 31
            Max = 255
            Min = -1
            TabOrder = 0
            OnChange = TrackBar3Change
          end
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'Edge detection - gradient'
        ImageIndex = 3
        object GroupBox7: TGroupBox
          Left = 0
          Top = 23
          Width = 337
          Height = 94
          Caption = 'Colors'
          TabOrder = 0
          object Label6: TLabel
            Left = 24
            Top = 32
            Width = 54
            Height = 13
            Caption = 'Edge color:'
          end
          object Label7: TLabel
            Left = 24
            Top = 64
            Width = 86
            Height = 13
            Caption = 'Background color:'
          end
          object PaintBox3: TPaintBox
            Left = 144
            Top = 32
            Width = 73
            Height = 17
            OnPaint = PaintBox3Paint
          end
          object PaintBox4: TPaintBox
            Left = 144
            Top = 64
            Width = 73
            Height = 16
            OnPaint = PaintBox4Paint
          end
          object Button9: TButton
            Left = 248
            Top = 30
            Width = 75
            Height = 25
            Caption = '...'
            TabOrder = 0
            OnClick = Button9Click
          end
          object Button10: TButton
            Left = 248
            Top = 60
            Width = 75
            Height = 25
            Caption = '...'
            TabOrder = 1
            OnClick = Button10Click
          end
          object CheckBox2: TCheckBox
            Left = 225
            Top = 31
            Width = 17
            Height = 17
            TabOrder = 2
          end
          object CheckBox3: TCheckBox
            Left = 225
            Top = 64
            Width = 17
            Height = 17
            TabOrder = 3
          end
        end
        object GroupBox8: TGroupBox
          Left = 384
          Top = 23
          Width = 289
          Height = 94
          Caption = 'Panel'
          TabOrder = 1
          object Label1: TLabel
            Left = 136
            Top = 21
            Width = 51
            Height = 13
            Caption = 'Threshold:'
          end
          object Label8: TLabel
            Left = 191
            Top = 21
            Width = 24
            Height = 13
            Caption = 'none'
          end
          object Button5: TButton
            Left = 22
            Top = 32
            Width = 91
            Height = 41
            Caption = 'Apply'
            TabOrder = 0
            OnClick = Button5Click
          end
          object TrackBar2: TTrackBar
            Left = 119
            Top = 40
            Width = 150
            Height = 33
            Max = 255
            Min = -1
            TabOrder = 1
            OnChange = TrackBar2Change
          end
        end
      end
      object TabSheet2: TTabSheet
        Caption = '9 Edge'
        ImageIndex = 3
        object GroupBox5: TGroupBox
          Left = 3
          Top = 16
          Width = 329
          Height = 105
          Caption = 'Colors'
          TabOrder = 0
          object Label3: TLabel
            Left = 16
            Top = 73
            Width = 86
            Height = 13
            Caption = 'background color:'
          end
          object Label2: TLabel
            Left = 16
            Top = 36
            Width = 54
            Height = 13
            Caption = 'edge color:'
          end
          object PaintBox2: TPaintBox
            Left = 112
            Top = 72
            Width = 81
            Height = 17
            OnPaint = PaintBox2Paint
          end
          object PaintBox1: TPaintBox
            Left = 112
            Top = 34
            Width = 81
            Height = 17
            OnPaint = PaintBox1Paint
          end
          object Button6: TButton
            Left = 222
            Top = 32
            Width = 75
            Height = 22
            Caption = '...'
            TabOrder = 0
            OnClick = Button6Click
          end
          object Button7: TButton
            Left = 222
            Top = 68
            Width = 75
            Height = 22
            Caption = '...'
            TabOrder = 1
            OnClick = Button7Click
          end
        end
        object GroupBox6: TGroupBox
          Left = 360
          Top = 16
          Width = 329
          Height = 105
          Caption = 'Panel'
          TabOrder = 1
          object Label4: TLabel
            Left = 160
            Top = 26
            Width = 62
            Height = 14
            Caption = 'Threshold:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object Label5: TLabel
            Left = 224
            Top = 29
            Width = 24
            Height = 13
            Caption = 'none'
          end
          object Button8: TButton
            Left = 16
            Top = 34
            Width = 89
            Height = 41
            Caption = 'Apply'
            TabOrder = 0
            OnClick = Button8Click
          end
          object TrackBar1: TTrackBar
            Left = 148
            Top = 45
            Width = 178
            Height = 37
            Max = 255
            Min = -1
            TabOrder = 1
            OnChange = TrackBar1Change
          end
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Noise'
        ImageIndex = 4
        object Button11: TButton
          Left = 256
          Top = 120
          Width = 177
          Height = 153
          Caption = 'Add noise'
          TabOrder = 0
          OnClick = Button11Click
        end
      end
    end
  end
  object ColorDialog1: TColorDialog
    Left = 352
    Top = 88
  end
end
