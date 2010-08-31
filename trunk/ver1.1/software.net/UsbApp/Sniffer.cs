using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using UsbLibrary;

namespace UsbApp
{
    public partial class Sniffer : Form
    {
        public Sniffer()
        {
            InitializeComponent();
        }

        private void usb_OnDeviceArrived(object sender, EventArgs e)
        {
            this.lb_message.Items.Insert(0, "Found a Device");
        }

        private void usb_OnDeviceRemoved(object sender, EventArgs e)
        {
            if (InvokeRequired)
            {
                Invoke(new EventHandler(usb_OnDeviceRemoved), new object[] { sender, e });
            }
            else
            {
                this.lb_message.Items.Insert(0, "Device was removed");
            }
        }

        private void usb_OnSpecifiedDeviceArrived(object sender, EventArgs e)
        {
            this.lb_message.Items.Insert(0, "My device was found");

            // Setting string form for sending data
            if (tb_send.Text == string.Empty)
            {
                string text = "";
                for (int i = 0; i < this.usb.SpecifiedDevice.OutputReportLength; i++)
                {
                    text += i.ToString("X2") + " ";
                }
                this.tb_send.Text = text;
            }
        }

        protected override void OnHandleCreated(EventArgs e)
        {
            base.OnHandleCreated(e);
            usb.RegisterHandle(Handle);
        }

        protected override void WndProc(ref Message m)
        {
            usb.ParseMessages(ref m);
            base.WndProc(ref m);	// pass message on to base form
        }

        private void btn_ok_Click(object sender, EventArgs e)
        {
            try
            {
                this.usb.VendorId  = 0x16C0;
                this.usb.ProductId = 0x05DF;
                
                this.usb.CheckDevicePresent();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void btn_send_Click(object sender, EventArgs e)
        {
            try
            {
                if (this.usb.SpecifiedDevice == null)
                {
                    MessageBox.Show("Sorry but your device is not present. Plug it in!! ");
                }
                else
                {
                    foreach (string x in this.tb_send.Text.Split('\n'))
                    {
                        string text = x.Trim();

                        if (!string.IsNullOrEmpty(text))
                        {
                            string[] arrText = text.Split(' ');
                            byte[] data = new byte[arrText.Length];
                            for (int i = 0; i < arrText.Length; i++)
                            {
                                if (arrText[i] != "")
                                {
                                    int value = Int32.Parse(arrText[i], System.Globalization.NumberStyles.Number);
                                    data[i] = (byte)Convert.ToByte(value);
                                }
                            }
                            if (this.usb.SpecifiedDevice != null)
                            {
                                this.usb.SpecifiedDevice.SendData(data);
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void usb_OnSpecifiedDeviceRemoved(object sender, EventArgs e)
        {
            if (InvokeRequired)
            {
                Invoke(new EventHandler(usb_OnSpecifiedDeviceRemoved), new object[] { sender, e });
            }
            else
            {
                this.lb_message.Items.Insert(0, "My device was removed");
            }
        }

        private void usb_OnDataRecieved(object sender, DataRecievedEventArgs args)
        {
            if (InvokeRequired)
            {
                try
                {
                    Invoke(new DataRecievedEventHandler(usb_OnDataRecieved), new object[] { sender, args });
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.ToString());
                }
            }
            else
            {
                string rec_data = string.Empty;
                foreach (byte myData in args.data)
                {
                    rec_data += myData.ToString("X2") + " ";
                }
                this.lb_read.Items.Insert(0, rec_data);
            }
        }

        private void usb_OnDataSend(object sender, EventArgs e)
        {
            this.lb_message.Items.Insert(0, "Some data was send");
        }
 
    }
}