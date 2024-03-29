namespace UsbApp
{
    partial class Sniffer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.lb_recieved = new System.Windows.Forms.Label();
            this.btn_send = new System.Windows.Forms.Button();
            this.tb_send = new System.Windows.Forms.TextBox();
            this.lb_vendor = new System.Windows.Forms.Label();
            this.btn_ok = new System.Windows.Forms.Button();
            this.lb_product = new System.Windows.Forms.Label();
            this.lb_messages = new System.Windows.Forms.Label();
            this.tb_vendor = new System.Windows.Forms.TextBox();
            this.tb_product = new System.Windows.Forms.TextBox();
            this.gb_filter = new System.Windows.Forms.GroupBox();
            this.lb_message = new System.Windows.Forms.ListBox();
            this.gb_details = new System.Windows.Forms.GroupBox();
            this.lb_read = new System.Windows.Forms.ListBox();
            this.usb = new UsbLibrary.UsbHidPort(this.components);
            this.gb_filter.SuspendLayout();
            this.gb_details.SuspendLayout();
            this.SuspendLayout();
            // 
            // lb_recieved
            // 
            this.lb_recieved.AutoSize = true;
            this.lb_recieved.Location = new System.Drawing.Point(193, 16);
            this.lb_recieved.Name = "lb_recieved";
            this.lb_recieved.Size = new System.Drawing.Size(82, 13);
            this.lb_recieved.TabIndex = 4;
            this.lb_recieved.Text = "Recieved Data:";
            // 
            // btn_send
            // 
            this.btn_send.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_send.Location = new System.Drawing.Point(575, 263);
            this.btn_send.Name = "btn_send";
            this.btn_send.Size = new System.Drawing.Size(48, 23);
            this.btn_send.TabIndex = 3;
            this.btn_send.Text = "&Send";
            this.btn_send.UseVisualStyleBackColor = true;
            this.btn_send.Click += new System.EventHandler(this.btn_send_Click);
            // 
            // tb_send
            // 
            this.tb_send.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.tb_send.Location = new System.Drawing.Point(196, 190);
            this.tb_send.Multiline = true;
            this.tb_send.Name = "tb_send";
            this.tb_send.Size = new System.Drawing.Size(373, 95);
            this.tb_send.TabIndex = 2;
            // 
            // lb_vendor
            // 
            this.lb_vendor.AutoSize = true;
            this.lb_vendor.Location = new System.Drawing.Point(6, 22);
            this.lb_vendor.Name = "lb_vendor";
            this.lb_vendor.Size = new System.Drawing.Size(58, 13);
            this.lb_vendor.TabIndex = 5;
            this.lb_vendor.Text = "Vendor ID:";
            // 
            // btn_ok
            // 
            this.btn_ok.Location = new System.Drawing.Point(144, 43);
            this.btn_ok.Name = "btn_ok";
            this.btn_ok.Size = new System.Drawing.Size(75, 23);
            this.btn_ok.TabIndex = 7;
            this.btn_ok.Text = "&Update";
            this.btn_ok.UseVisualStyleBackColor = true;
            this.btn_ok.Click += new System.EventHandler(this.btn_ok_Click);
            // 
            // lb_product
            // 
            this.lb_product.AutoSize = true;
            this.lb_product.Location = new System.Drawing.Point(6, 48);
            this.lb_product.Name = "lb_product";
            this.lb_product.Size = new System.Drawing.Size(61, 13);
            this.lb_product.TabIndex = 6;
            this.lb_product.Text = "Product ID:";
            // 
            // lb_messages
            // 
            this.lb_messages.AutoSize = true;
            this.lb_messages.Location = new System.Drawing.Point(8, 16);
            this.lb_messages.Name = "lb_messages";
            this.lb_messages.Size = new System.Drawing.Size(83, 13);
            this.lb_messages.TabIndex = 7;
            this.lb_messages.Text = "USB Messages:";
            // 
            // tb_vendor
            // 
            this.tb_vendor.Location = new System.Drawing.Point(87, 19);
            this.tb_vendor.Name = "tb_vendor";
            this.tb_vendor.Size = new System.Drawing.Size(51, 20);
            this.tb_vendor.TabIndex = 1;
            this.tb_vendor.Text = "16C0";
            // 
            // tb_product
            // 
            this.tb_product.Location = new System.Drawing.Point(87, 45);
            this.tb_product.Name = "tb_product";
            this.tb_product.Size = new System.Drawing.Size(51, 20);
            this.tb_product.TabIndex = 2;
            this.tb_product.Text = "05DF";
            // 
            // gb_filter
            // 
            this.gb_filter.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.gb_filter.Controls.Add(this.btn_ok);
            this.gb_filter.Controls.Add(this.lb_product);
            this.gb_filter.Controls.Add(this.lb_vendor);
            this.gb_filter.Controls.Add(this.tb_vendor);
            this.gb_filter.Controls.Add(this.tb_product);
            this.gb_filter.Location = new System.Drawing.Point(12, 12);
            this.gb_filter.Name = "gb_filter";
            this.gb_filter.Size = new System.Drawing.Size(629, 80);
            this.gb_filter.TabIndex = 5;
            this.gb_filter.TabStop = false;
            this.gb_filter.Text = "Device Filter";
            // 
            // lb_message
            // 
            this.lb_message.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.lb_message.FormattingEnabled = true;
            this.lb_message.IntegralHeight = false;
            this.lb_message.Location = new System.Drawing.Point(11, 32);
            this.lb_message.Name = "lb_message";
            this.lb_message.Size = new System.Drawing.Size(179, 253);
            this.lb_message.TabIndex = 6;
            // 
            // gb_details
            // 
            this.gb_details.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.gb_details.Controls.Add(this.lb_read);
            this.gb_details.Controls.Add(this.lb_messages);
            this.gb_details.Controls.Add(this.lb_message);
            this.gb_details.Controls.Add(this.lb_recieved);
            this.gb_details.Controls.Add(this.btn_send);
            this.gb_details.Controls.Add(this.tb_send);
            this.gb_details.Location = new System.Drawing.Point(12, 98);
            this.gb_details.Name = "gb_details";
            this.gb_details.Size = new System.Drawing.Size(629, 291);
            this.gb_details.TabIndex = 6;
            this.gb_details.TabStop = false;
            this.gb_details.Text = "Details";
            // 
            // lb_read
            // 
            this.lb_read.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.lb_read.FormattingEnabled = true;
            this.lb_read.IntegralHeight = false;
            this.lb_read.Location = new System.Drawing.Point(196, 32);
            this.lb_read.Name = "lb_read";
            this.lb_read.Size = new System.Drawing.Size(427, 152);
            this.lb_read.TabIndex = 8;
            // 
            // usb
            // 
            this.usb.VendorId  = 0x16C0;
            this.usb.ProductId = 0x05DF;
            this.usb.OnSpecifiedDeviceRemoved += new System.EventHandler(this.usb_OnSpecifiedDeviceRemoved);
            this.usb.OnDeviceArrived += new System.EventHandler(this.usb_OnDeviceArrived);
            this.usb.OnDeviceRemoved += new System.EventHandler(this.usb_OnDeviceRemoved);
            this.usb.OnDataRecieved += new UsbLibrary.DataRecievedEventHandler(this.usb_OnDataRecieved);
            this.usb.OnSpecifiedDeviceArrived += new System.EventHandler(this.usb_OnSpecifiedDeviceArrived);
            this.usb.OnDataSend += new System.EventHandler(this.usb_OnDataSend);
            // 
            // Sniffer
            // 
            this.AcceptButton = this.btn_send;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(653, 401);
            this.Controls.Add(this.gb_filter);
            this.Controls.Add(this.gb_details);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Sniffer";
            this.Text = "Sniffer";
            this.gb_filter.ResumeLayout(false);
            this.gb_filter.PerformLayout();
            this.gb_details.ResumeLayout(false);
            this.gb_details.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lb_recieved;
        private System.Windows.Forms.Button btn_send;
        private System.Windows.Forms.TextBox tb_send;
        private System.Windows.Forms.Label lb_vendor;
        private System.Windows.Forms.Button btn_ok;
        private System.Windows.Forms.Label lb_product;
        private System.Windows.Forms.Label lb_messages;
        private System.Windows.Forms.TextBox tb_vendor;
        private System.Windows.Forms.TextBox tb_product;
        private System.Windows.Forms.GroupBox gb_filter;
        private System.Windows.Forms.ListBox lb_message;
        private System.Windows.Forms.GroupBox gb_details;
        private UsbLibrary.UsbHidPort usb;
        private System.Windows.Forms.ListBox lb_read;

    }
}

