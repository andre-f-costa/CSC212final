namespace CSC212Final
{
    partial class RecursiveImaging
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
            this.txt_output = new System.Windows.Forms.TextBox();
            this.txt_iterations = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btn_hil = new System.Windows.Forms.RadioButton();
            this.btn_ser = new System.Windows.Forms.RadioButton();
            this.btn_koch = new System.Windows.Forms.RadioButton();
            this.txt_size = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txt_prog = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(449, 343);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Run";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // txt_output
            // 
            this.txt_output.Location = new System.Drawing.Point(45, 127);
            this.txt_output.Name = "txt_output";
            this.txt_output.Size = new System.Drawing.Size(479, 20);
            this.txt_output.TabIndex = 1;
            this.txt_output.TextChanged += new System.EventHandler(this.txt_output_TextChanged);
            // 
            // txt_iterations
            // 
            this.txt_iterations.ForeColor = System.Drawing.Color.Black;
            this.txt_iterations.Location = new System.Drawing.Point(45, 188);
            this.txt_iterations.Name = "txt_iterations";
            this.txt_iterations.Size = new System.Drawing.Size(120, 20);
            this.txt_iterations.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(42, 111);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(102, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "File Output Location";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(42, 172);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(96, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Numer of Iterations";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(42, 287);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Image Type";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(40, 20);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(306, 25);
            this.label4.TabIndex = 7;
            this.label4.Text = "Recursive Imaging CSC 212";
            // 
            // btn_hil
            // 
            this.btn_hil.AutoSize = true;
            this.btn_hil.ForeColor = System.Drawing.Color.White;
            this.btn_hil.Location = new System.Drawing.Point(45, 303);
            this.btn_hil.Name = "btn_hil";
            this.btn_hil.Size = new System.Drawing.Size(86, 17);
            this.btn_hil.TabIndex = 8;
            this.btn_hil.TabStop = true;
            this.btn_hil.Text = "Hilbert Curve";
            this.btn_hil.UseVisualStyleBackColor = true;
            this.btn_hil.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // btn_ser
            // 
            this.btn_ser.AutoSize = true;
            this.btn_ser.ForeColor = System.Drawing.Color.White;
            this.btn_ser.Location = new System.Drawing.Point(45, 326);
            this.btn_ser.Name = "btn_ser";
            this.btn_ser.Size = new System.Drawing.Size(109, 17);
            this.btn_ser.TabIndex = 9;
            this.btn_ser.TabStop = true;
            this.btn_ser.Text = "Serpinski Triangle";
            this.btn_ser.UseVisualStyleBackColor = true;
            this.btn_ser.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // btn_koch
            // 
            this.btn_koch.AutoSize = true;
            this.btn_koch.ForeColor = System.Drawing.Color.White;
            this.btn_koch.Location = new System.Drawing.Point(45, 349);
            this.btn_koch.Name = "btn_koch";
            this.btn_koch.Size = new System.Drawing.Size(91, 17);
            this.btn_koch.TabIndex = 10;
            this.btn_koch.TabStop = true;
            this.btn_koch.Text = "Koch Triangle";
            this.btn_koch.UseVisualStyleBackColor = true;
            this.btn_koch.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // txt_size
            // 
            this.txt_size.Location = new System.Drawing.Point(45, 247);
            this.txt_size.Name = "txt_size";
            this.txt_size.Size = new System.Drawing.Size(100, 20);
            this.txt_size.TabIndex = 11;
            this.txt_size.TextChanged += new System.EventHandler(this.txt_size_TextChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(42, 231);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(74, 13);
            this.label5.TabIndex = 12;
            this.label5.Text = "Size of Output";
            // 
            // txt_prog
            // 
            this.txt_prog.Location = new System.Drawing.Point(45, 67);
            this.txt_prog.Name = "txt_prog";
            this.txt_prog.Size = new System.Drawing.Size(479, 20);
            this.txt_prog.TabIndex = 13;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(42, 51);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(90, 13);
            this.label6.TabIndex = 14;
            this.label6.Text = "Program Location";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(341, 51);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(183, 13);
            this.label7.TabIndex = 15;
            this.label7.Text = "Please start all file locations with /mnt";
            // 
            // RecursiveImaging
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(100)))));
            this.ClientSize = new System.Drawing.Size(578, 423);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txt_prog);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txt_size);
            this.Controls.Add(this.btn_koch);
            this.Controls.Add(this.btn_ser);
            this.Controls.Add(this.btn_hil);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txt_iterations);
            this.Controls.Add(this.txt_output);
            this.Controls.Add(this.button1);
            this.Name = "RecursiveImaging";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox txt_output;
        private System.Windows.Forms.TextBox txt_iterations;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.RadioButton btn_hil;
        private System.Windows.Forms.RadioButton btn_ser;
        private System.Windows.Forms.RadioButton btn_koch;
        private System.Windows.Forms.TextBox txt_size;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txt_prog;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
    }
}

