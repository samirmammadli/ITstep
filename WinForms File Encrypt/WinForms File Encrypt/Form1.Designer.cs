namespace WinForms_File_Encrypt
{
    partial class FormMain
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
            this.plMain = new System.Windows.Forms.Panel();
            this.btCancel = new System.Windows.Forms.Button();
            this.lbKey = new System.Windows.Forms.Label();
            this.tbKey = new System.Windows.Forms.TextBox();
            this.tbFileName = new System.Windows.Forms.TextBox();
            this.btSelectDecrypt = new System.Windows.Forms.Button();
            this.lbFileName = new System.Windows.Forms.Label();
            this.btSelectEncrypt = new System.Windows.Forms.Button();
            this.fdOpen = new System.Windows.Forms.OpenFileDialog();
            this.plOpenFile = new System.Windows.Forms.Panel();
            this.btExit = new System.Windows.Forms.Button();
            this.btOpenFile = new System.Windows.Forms.Button();
            this.plMain.SuspendLayout();
            this.plOpenFile.SuspendLayout();
            this.SuspendLayout();
            // 
            // plMain
            // 
            this.plMain.Controls.Add(this.btCancel);
            this.plMain.Controls.Add(this.lbKey);
            this.plMain.Controls.Add(this.tbKey);
            this.plMain.Controls.Add(this.tbFileName);
            this.plMain.Controls.Add(this.btSelectDecrypt);
            this.plMain.Controls.Add(this.lbFileName);
            this.plMain.Controls.Add(this.btSelectEncrypt);
            this.plMain.Location = new System.Drawing.Point(12, 12);
            this.plMain.Name = "plMain";
            this.plMain.Size = new System.Drawing.Size(404, 103);
            this.plMain.TabIndex = 0;
            this.plMain.Visible = false;
            // 
            // btCancel
            // 
            this.btCancel.Location = new System.Drawing.Point(271, 63);
            this.btCancel.Name = "btCancel";
            this.btCancel.Size = new System.Drawing.Size(128, 37);
            this.btCancel.TabIndex = 6;
            this.btCancel.Text = "Cancel";
            this.btCancel.UseVisualStyleBackColor = true;
            this.btCancel.Click += new System.EventHandler(this.btCancel_Click);
            // 
            // lbKey
            // 
            this.lbKey.AutoSize = true;
            this.lbKey.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbKey.Location = new System.Drawing.Point(3, 29);
            this.lbKey.Name = "lbKey";
            this.lbKey.Size = new System.Drawing.Size(30, 15);
            this.lbKey.TabIndex = 5;
            this.lbKey.Text = "Key:";
            // 
            // tbKey
            // 
            this.tbKey.Location = new System.Drawing.Point(37, 29);
            this.tbKey.Name = "tbKey";
            this.tbKey.Size = new System.Drawing.Size(353, 20);
            this.tbKey.TabIndex = 4;
            // 
            // tbFileName
            // 
            this.tbFileName.Enabled = false;
            this.tbFileName.Location = new System.Drawing.Point(37, 0);
            this.tbFileName.Multiline = true;
            this.tbFileName.Name = "tbFileName";
            this.tbFileName.Size = new System.Drawing.Size(353, 22);
            this.tbFileName.TabIndex = 3;
            // 
            // btSelectDecrypt
            // 
            this.btSelectDecrypt.Location = new System.Drawing.Point(137, 63);
            this.btSelectDecrypt.Name = "btSelectDecrypt";
            this.btSelectDecrypt.Size = new System.Drawing.Size(128, 37);
            this.btSelectDecrypt.TabIndex = 1;
            this.btSelectDecrypt.Text = "DecryptBytes File";
            this.btSelectDecrypt.UseVisualStyleBackColor = true;
            this.btSelectDecrypt.Click += new System.EventHandler(this.btSelectDecrypt_Click);
            // 
            // lbFileName
            // 
            this.lbFileName.AutoSize = true;
            this.lbFileName.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lbFileName.Location = new System.Drawing.Point(3, 0);
            this.lbFileName.Name = "lbFileName";
            this.lbFileName.Size = new System.Drawing.Size(33, 15);
            this.lbFileName.TabIndex = 2;
            this.lbFileName.Text = "File: ";
            // 
            // btSelectEncrypt
            // 
            this.btSelectEncrypt.Location = new System.Drawing.Point(3, 63);
            this.btSelectEncrypt.Name = "btSelectEncrypt";
            this.btSelectEncrypt.Size = new System.Drawing.Size(128, 37);
            this.btSelectEncrypt.TabIndex = 0;
            this.btSelectEncrypt.Text = "EncryptBytes File";
            this.btSelectEncrypt.UseVisualStyleBackColor = true;
            this.btSelectEncrypt.Click += new System.EventHandler(this.btSelectEncrypt_Click);
            // 
            // fdOpen
            // 
            this.fdOpen.FileName = "fdOpen";
            // 
            // plOpenFile
            // 
            this.plOpenFile.Controls.Add(this.btExit);
            this.plOpenFile.Controls.Add(this.btOpenFile);
            this.plOpenFile.Location = new System.Drawing.Point(7, 12);
            this.plOpenFile.Name = "plOpenFile";
            this.plOpenFile.Size = new System.Drawing.Size(404, 99);
            this.plOpenFile.TabIndex = 1;
            // 
            // btExit
            // 
            this.btExit.Location = new System.Drawing.Point(262, 28);
            this.btExit.Name = "btExit";
            this.btExit.Size = new System.Drawing.Size(128, 37);
            this.btExit.TabIndex = 1;
            this.btExit.Text = "Exit";
            this.btExit.UseVisualStyleBackColor = true;
            this.btExit.Click += new System.EventHandler(this.btExit_Click);
            // 
            // btOpenFile
            // 
            this.btOpenFile.Location = new System.Drawing.Point(20, 28);
            this.btOpenFile.Name = "btOpenFile";
            this.btOpenFile.Size = new System.Drawing.Size(128, 37);
            this.btOpenFile.TabIndex = 0;
            this.btOpenFile.Text = "Open File";
            this.btOpenFile.UseVisualStyleBackColor = true;
            this.btOpenFile.Click += new System.EventHandler(this.btOpenFile_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.ClientSize = new System.Drawing.Size(425, 123);
            this.Controls.Add(this.plOpenFile);
            this.Controls.Add(this.plMain);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "FormMain";
            this.Text = "File Encryptor";
            this.plMain.ResumeLayout(false);
            this.plMain.PerformLayout();
            this.plOpenFile.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel plMain;
        private System.Windows.Forms.Button btSelectDecrypt;
        private System.Windows.Forms.Button btSelectEncrypt;
        private System.Windows.Forms.OpenFileDialog fdOpen;
        private System.Windows.Forms.Label lbFileName;
        private System.Windows.Forms.TextBox tbFileName;
        private System.Windows.Forms.Label lbKey;
        private System.Windows.Forms.TextBox tbKey;
        private System.Windows.Forms.Panel plOpenFile;
        private System.Windows.Forms.Button btOpenFile;
        private System.Windows.Forms.Button btCancel;
        private System.Windows.Forms.Button btExit;
    }
}

