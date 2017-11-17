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
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.fileSystemWatcher1 = new System.IO.FileSystemWatcher();
            this.DisplayMessagesBox = new System.Windows.Forms.TextBox();
            this.ChatBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(699, 83);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(108, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Log In";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(699, 112);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(108, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "Registration";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Rockwell", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.LightSeaGreen;
            this.label1.Location = new System.Drawing.Point(619, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(263, 48);
            this.label1.TabIndex = 2;
            this.label1.Text = "Please, Log in.\r\nOr register a new account";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // fileSystemWatcher1
            // 
            this.fileSystemWatcher1.EnableRaisingEvents = true;
            this.fileSystemWatcher1.SynchronizingObject = this;
            this.fileSystemWatcher1.Changed += new System.IO.FileSystemEventHandler(this.fileSystemWatcher1_Changed);
            // 
            // DisplayMessagesBox
            // 
            this.DisplayMessagesBox.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.DisplayMessagesBox.Font = new System.Drawing.Font("Arial Unicode MS", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DisplayMessagesBox.ForeColor = System.Drawing.SystemColors.WindowText;
            this.DisplayMessagesBox.Location = new System.Drawing.Point(12, 12);
            this.DisplayMessagesBox.Multiline = true;
            this.DisplayMessagesBox.Name = "DisplayMessagesBox";
            this.DisplayMessagesBox.ReadOnly = true;
            this.DisplayMessagesBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.DisplayMessagesBox.Size = new System.Drawing.Size(573, 460);
            this.DisplayMessagesBox.TabIndex = 4;
            this.DisplayMessagesBox.TextChanged += new System.EventHandler(this.DisplayMessagesBox_TextChanged);
            // 
            // ChatBox
            // 
            this.ChatBox.AcceptsReturn = true;
            this.ChatBox.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.ChatBox.Location = new System.Drawing.Point(12, 491);
            this.ChatBox.Multiline = true;
            this.ChatBox.Name = "ChatBox";
            this.ChatBox.Size = new System.Drawing.Size(573, 20);
            this.ChatBox.TabIndex = 5;
            this.ChatBox.TextChanged += new System.EventHandler(this.ChatBox_TextChanged);
            this.ChatBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.ChatBox_KeyDown);
            // 
            // Form1
            // 
            this.AccessibleName = "";
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(894, 523);
            this.Controls.Add(this.ChatBox);
            this.Controls.Add(this.DisplayMessagesBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Дешевая Версия mIRC";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label1;
        private System.IO.FileSystemWatcher fileSystemWatcher1;
        private System.Windows.Forms.TextBox DisplayMessagesBox;
        private System.Windows.Forms.TextBox ChatBox;
    }
}

