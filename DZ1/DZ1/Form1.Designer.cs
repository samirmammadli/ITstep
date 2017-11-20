namespace DZ1
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.lbAge = new System.Windows.Forms.Label();
            this.lbSurname = new System.Windows.Forms.Label();
            this.lbName = new System.Windows.Forms.Label();
            this.tbCancelFill = new System.Windows.Forms.Button();
            this.tbName = new System.Windows.Forms.TextBox();
            this.btRegister = new System.Windows.Forms.Button();
            this.tbSurname = new System.Windows.Forms.TextBox();
            this.tbAge = new System.Windows.Forms.TextBox();
            this.btLogin = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.ChatBox = new System.Windows.Forms.TextBox();
            this.lbLogin = new System.Windows.Forms.Label();
            this.lbPassword = new System.Windows.Forms.Label();
            this.tbLogin = new System.Windows.Forms.TextBox();
            this.tbPassword = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.btRegistration = new System.Windows.Forms.Button();
            this.lbReg = new System.Windows.Forms.Label();
            this.regPanel = new System.Windows.Forms.Panel();
            this.loginPanel = new System.Windows.Forms.Panel();
            this.LogOutPanel = new System.Windows.Forms.Panel();
            this.btLogOut = new System.Windows.Forms.Button();
            this.lbLoggedName = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.regPanel.SuspendLayout();
            this.loginPanel.SuspendLayout();
            this.LogOutPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbAge
            // 
            this.lbAge.AutoSize = true;
            this.lbAge.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbAge.Location = new System.Drawing.Point(10, 89);
            this.lbAge.Name = "lbAge";
            this.lbAge.Size = new System.Drawing.Size(33, 16);
            this.lbAge.TabIndex = 22;
            this.lbAge.Text = "Age";
            // 
            // lbSurname
            // 
            this.lbSurname.AutoSize = true;
            this.lbSurname.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbSurname.Location = new System.Drawing.Point(10, 63);
            this.lbSurname.Name = "lbSurname";
            this.lbSurname.Size = new System.Drawing.Size(62, 16);
            this.lbSurname.TabIndex = 21;
            this.lbSurname.Text = "Surname";
            // 
            // lbName
            // 
            this.lbName.AutoSize = true;
            this.lbName.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbName.Location = new System.Drawing.Point(10, 34);
            this.lbName.Name = "lbName";
            this.lbName.Size = new System.Drawing.Size(45, 16);
            this.lbName.TabIndex = 20;
            this.lbName.Text = "Name";
            // 
            // tbCancelFill
            // 
            this.tbCancelFill.Location = new System.Drawing.Point(164, 115);
            this.tbCancelFill.Name = "tbCancelFill";
            this.tbCancelFill.Size = new System.Drawing.Size(75, 23);
            this.tbCancelFill.TabIndex = 19;
            this.tbCancelFill.Text = "Cancel";
            this.tbCancelFill.UseVisualStyleBackColor = true;
            this.tbCancelFill.Click += new System.EventHandler(this.tbCancelFill_Click);
            // 
            // tbName
            // 
            this.tbName.Location = new System.Drawing.Point(83, 37);
            this.tbName.Name = "tbName";
            this.tbName.Size = new System.Drawing.Size(212, 20);
            this.tbName.TabIndex = 15;
            // 
            // btRegister
            // 
            this.btRegister.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btRegister.FlatAppearance.BorderSize = 3;
            this.btRegister.Location = new System.Drawing.Point(83, 115);
            this.btRegister.Name = "btRegister";
            this.btRegister.Size = new System.Drawing.Size(75, 23);
            this.btRegister.TabIndex = 18;
            this.btRegister.Text = "Register";
            this.btRegister.UseVisualStyleBackColor = true;
            this.btRegister.Click += new System.EventHandler(this.btRegister_Click);
            // 
            // tbSurname
            // 
            this.tbSurname.Location = new System.Drawing.Point(83, 63);
            this.tbSurname.Name = "tbSurname";
            this.tbSurname.Size = new System.Drawing.Size(212, 20);
            this.tbSurname.TabIndex = 16;
            // 
            // tbAge
            // 
            this.tbAge.Location = new System.Drawing.Point(83, 89);
            this.tbAge.Name = "tbAge";
            this.tbAge.Size = new System.Drawing.Size(43, 20);
            this.tbAge.TabIndex = 17;
            // 
            // btLogin
            // 
            this.btLogin.Location = new System.Drawing.Point(88, 102);
            this.btLogin.Name = "btLogin";
            this.btLogin.Size = new System.Drawing.Size(108, 23);
            this.btLogin.TabIndex = 0;
            this.btLogin.Text = "Log In";
            this.btLogin.UseVisualStyleBackColor = true;
            this.btLogin.Click += new System.EventHandler(this.btLogin_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Rockwell", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.LightSeaGreen;
            this.label1.Location = new System.Drawing.Point(12, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(155, 24);
            this.label1.TabIndex = 2;
            this.label1.Text = "Please, Log in.\r\n";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // ChatBox
            // 
            this.ChatBox.AcceptsReturn = true;
            this.ChatBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.ChatBox.Enabled = false;
            this.ChatBox.Location = new System.Drawing.Point(12, 491);
            this.ChatBox.Name = "ChatBox";
            this.ChatBox.Size = new System.Drawing.Size(573, 20);
            this.ChatBox.TabIndex = 5;
            this.ChatBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.ChatBox_KeyDown);
            // 
            // lbLogin
            // 
            this.lbLogin.AutoSize = true;
            this.lbLogin.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbLogin.Location = new System.Drawing.Point(16, 47);
            this.lbLogin.Name = "lbLogin";
            this.lbLogin.Size = new System.Drawing.Size(41, 16);
            this.lbLogin.TabIndex = 6;
            this.lbLogin.Text = "Login";
            // 
            // lbPassword
            // 
            this.lbPassword.AutoSize = true;
            this.lbPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbPassword.Location = new System.Drawing.Point(16, 76);
            this.lbPassword.Name = "lbPassword";
            this.lbPassword.Size = new System.Drawing.Size(68, 16);
            this.lbPassword.TabIndex = 7;
            this.lbPassword.Text = "Password";
            // 
            // tbLogin
            // 
            this.tbLogin.Location = new System.Drawing.Point(88, 46);
            this.tbLogin.Name = "tbLogin";
            this.tbLogin.Size = new System.Drawing.Size(215, 20);
            this.tbLogin.TabIndex = 8;
            // 
            // tbPassword
            // 
            this.tbPassword.Location = new System.Drawing.Point(88, 76);
            this.tbPassword.Name = "tbPassword";
            this.tbPassword.PasswordChar = '*';
            this.tbPassword.Size = new System.Drawing.Size(215, 20);
            this.tbPassword.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Rockwell", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.LightSeaGreen;
            this.label4.Location = new System.Drawing.Point(12, 131);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(270, 24);
            this.label4.TabIndex = 10;
            this.label4.Text = "Or register a new account.";
            this.label4.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // btRegistration
            // 
            this.btRegistration.Location = new System.Drawing.Point(88, 161);
            this.btRegistration.Name = "btRegistration";
            this.btRegistration.Size = new System.Drawing.Size(108, 23);
            this.btRegistration.TabIndex = 1;
            this.btRegistration.Text = "Registration";
            this.btRegistration.UseVisualStyleBackColor = true;
            this.btRegistration.Click += new System.EventHandler(this.btRegistration_Click);
            // 
            // lbReg
            // 
            this.lbReg.AutoSize = true;
            this.lbReg.Font = new System.Drawing.Font("Rockwell", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbReg.ForeColor = System.Drawing.Color.LightSeaGreen;
            this.lbReg.Location = new System.Drawing.Point(79, 4);
            this.lbReg.Name = "lbReg";
            this.lbReg.Size = new System.Drawing.Size(132, 24);
            this.lbReg.TabIndex = 21;
            this.lbReg.Text = "Registration";
            this.lbReg.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // regPanel
            // 
            this.regPanel.Controls.Add(this.lbReg);
            this.regPanel.Controls.Add(this.lbSurname);
            this.regPanel.Controls.Add(this.lbAge);
            this.regPanel.Controls.Add(this.tbAge);
            this.regPanel.Controls.Add(this.tbSurname);
            this.regPanel.Controls.Add(this.lbName);
            this.regPanel.Controls.Add(this.btRegister);
            this.regPanel.Controls.Add(this.tbCancelFill);
            this.regPanel.Controls.Add(this.tbName);
            this.regPanel.Location = new System.Drawing.Point(591, 12);
            this.regPanel.Name = "regPanel";
            this.regPanel.Size = new System.Drawing.Size(318, 147);
            this.regPanel.TabIndex = 21;
            this.regPanel.Visible = false;
            // 
            // loginPanel
            // 
            this.loginPanel.Controls.Add(this.label1);
            this.loginPanel.Controls.Add(this.btLogin);
            this.loginPanel.Controls.Add(this.btRegistration);
            this.loginPanel.Controls.Add(this.lbLogin);
            this.loginPanel.Controls.Add(this.label4);
            this.loginPanel.Controls.Add(this.lbPassword);
            this.loginPanel.Controls.Add(this.tbPassword);
            this.loginPanel.Controls.Add(this.tbLogin);
            this.loginPanel.Location = new System.Drawing.Point(590, 12);
            this.loginPanel.Name = "loginPanel";
            this.loginPanel.Size = new System.Drawing.Size(316, 196);
            this.loginPanel.TabIndex = 22;
            // 
            // LogOutPanel
            // 
            this.LogOutPanel.Controls.Add(this.btLogOut);
            this.LogOutPanel.Controls.Add(this.lbLoggedName);
            this.LogOutPanel.Location = new System.Drawing.Point(591, 12);
            this.LogOutPanel.Name = "LogOutPanel";
            this.LogOutPanel.Size = new System.Drawing.Size(318, 62);
            this.LogOutPanel.TabIndex = 23;
            this.LogOutPanel.Visible = false;
            // 
            // btLogOut
            // 
            this.btLogOut.Location = new System.Drawing.Point(6, 34);
            this.btLogOut.Name = "btLogOut";
            this.btLogOut.Size = new System.Drawing.Size(75, 23);
            this.btLogOut.TabIndex = 4;
            this.btLogOut.Text = "Log out";
            this.btLogOut.UseVisualStyleBackColor = true;
            this.btLogOut.Click += new System.EventHandler(this.btLogOut_Click);
            // 
            // lbLoggedName
            // 
            this.lbLoggedName.AutoSize = true;
            this.lbLoggedName.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbLoggedName.ForeColor = System.Drawing.Color.Green;
            this.lbLoggedName.Location = new System.Drawing.Point(3, 9);
            this.lbLoggedName.Name = "lbLoggedName";
            this.lbLoggedName.Size = new System.Drawing.Size(114, 16);
            this.lbLoggedName.TabIndex = 3;
            this.lbLoggedName.Text = "Name Surname";
            this.lbLoggedName.TextAlign = System.Drawing.ContentAlignment.TopRight;
            // 
            // richTextBox1
            // 
            this.richTextBox1.BackColor = System.Drawing.Color.SeaShell;
            this.richTextBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.richTextBox1.Location = new System.Drawing.Point(11, 12);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.Vertical;
            this.richTextBox1.Size = new System.Drawing.Size(573, 452);
            this.richTextBox1.TabIndex = 24;
            this.richTextBox1.Text = "";
            // 
            // colorDialog1
            // 
            this.colorDialog1.FullOpen = true;
            // 
            // Form1
            // 
            this.AccessibleName = "";
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(921, 523);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.LogOutPanel);
            this.Controls.Add(this.loginPanel);
            this.Controls.Add(this.regPanel);
            this.Controls.Add(this.ChatBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Дешевая Версия mIRC";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.regPanel.ResumeLayout(false);
            this.regPanel.PerformLayout();
            this.loginPanel.ResumeLayout(false);
            this.loginPanel.PerformLayout();
            this.LogOutPanel.ResumeLayout(false);
            this.LogOutPanel.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btLogin;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox ChatBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox tbPassword;
        private System.Windows.Forms.TextBox tbLogin;
        private System.Windows.Forms.Label lbPassword;
        private System.Windows.Forms.Label lbLogin;
        private System.Windows.Forms.Button btRegistration;
        private System.Windows.Forms.Button tbCancelFill;
        private System.Windows.Forms.TextBox tbName;
        private System.Windows.Forms.Button btRegister;
        private System.Windows.Forms.TextBox tbSurname;
        private System.Windows.Forms.TextBox tbAge;
        private System.Windows.Forms.Label lbAge;
        private System.Windows.Forms.Label lbSurname;
        private System.Windows.Forms.Label lbName;
        private System.Windows.Forms.Label lbReg;
        private System.Windows.Forms.Panel regPanel;
        private System.Windows.Forms.Panel loginPanel;
        private System.Windows.Forms.Panel LogOutPanel;
        private System.Windows.Forms.Button btLogOut;
        private System.Windows.Forms.Label lbLoggedName;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.ColorDialog colorDialog1;
    }
}

