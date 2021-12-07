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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(RecursiveImaging));
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
            this.label8 = new System.Windows.Forms.Label();
            this.btn_carp = new System.Windows.Forms.RadioButton();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(1400, 1032);
            this.button1.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(238, 65);
            this.button1.TabIndex = 0;
            this.button1.Text = "Run";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // txt_output
            // 
            this.txt_output.Location = new System.Drawing.Point(142, 361);
            this.txt_output.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.txt_output.Name = "txt_output";
            this.txt_output.Size = new System.Drawing.Size(1508, 44);
            this.txt_output.TabIndex = 1;
            this.txt_output.TextChanged += new System.EventHandler(this.txt_output_TextChanged);
            // 
            // txt_iterations
            // 
            this.txt_iterations.ForeColor = System.Drawing.Color.Black;
            this.txt_iterations.Location = new System.Drawing.Point(142, 876);
            this.txt_iterations.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.txt_iterations.Name = "txt_iterations";
            this.txt_iterations.Size = new System.Drawing.Size(371, 44);
            this.txt_iterations.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(133, 316);
            this.label1.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(305, 37);
            this.label1.TabIndex = 4;
            this.label1.Text = "File Output Location";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(133, 830);
            this.label2.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(290, 37);
            this.label2.TabIndex = 5;
            this.label2.Text = "Numer of Iterations";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(133, 492);
            this.label3.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(184, 37);
            this.label3.TabIndex = 6;
            this.label3.Text = "Image Type";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.White;
            this.label4.Location = new System.Drawing.Point(127, 57);
            this.label4.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(848, 72);
            this.label4.TabIndex = 7;
            this.label4.Text = "Recursive Imaging CSC 212";
            // 
            // btn_hil
            // 
            this.btn_hil.AutoSize = true;
            this.btn_hil.ForeColor = System.Drawing.Color.White;
            this.btn_hil.Location = new System.Drawing.Point(142, 538);
            this.btn_hil.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.btn_hil.Name = "btn_hil";
            this.btn_hil.Size = new System.Drawing.Size(246, 41);
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
            this.btn_ser.Location = new System.Drawing.Point(142, 603);
            this.btn_ser.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.btn_ser.Name = "btn_ser";
            this.btn_ser.Size = new System.Drawing.Size(324, 41);
            this.btn_ser.TabIndex = 9;
            this.btn_ser.TabStop = true;
            this.btn_ser.Text = "Sierpinski Triangle";
            this.btn_ser.UseVisualStyleBackColor = true;
            this.btn_ser.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // btn_koch
            // 
            this.btn_koch.AutoSize = true;
            this.btn_koch.ForeColor = System.Drawing.Color.White;
            this.btn_koch.Location = new System.Drawing.Point(142, 727);
            this.btn_koch.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.btn_koch.Name = "btn_koch";
            this.btn_koch.Size = new System.Drawing.Size(259, 41);
            this.btn_koch.TabIndex = 10;
            this.btn_koch.TabStop = true;
            this.btn_koch.Text = "Koch Triangle";
            this.btn_koch.UseVisualStyleBackColor = true;
            this.btn_koch.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // txt_size
            // 
            this.txt_size.Location = new System.Drawing.Point(142, 1043);
            this.txt_size.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.txt_size.Name = "txt_size";
            this.txt_size.Size = new System.Drawing.Size(308, 44);
            this.txt_size.TabIndex = 11;
            this.txt_size.TextChanged += new System.EventHandler(this.txt_size_TextChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(133, 998);
            this.label5.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(220, 37);
            this.label5.TabIndex = 12;
            this.label5.Text = "Size of Output";
            // 
            // txt_prog
            // 
            this.txt_prog.Location = new System.Drawing.Point(142, 191);
            this.txt_prog.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.txt_prog.Name = "txt_prog";
            this.txt_prog.Size = new System.Drawing.Size(1508, 44);
            this.txt_prog.TabIndex = 13;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(133, 145);
            this.label6.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(272, 37);
            this.label6.TabIndex = 14;
            this.label6.Text = "Program Location";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(705, 314);
            this.label7.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(945, 38);
            this.label7.TabIndex = 15;
            this.label7.Text = "Please input file location following Linux format starting with /mnt";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Location = new System.Drawing.Point(1479, 1144);
            this.label8.Margin = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(291, 31);
            this.label8.TabIndex = 16;
            this.label8.Text = "André Costa, Fall 2021";
            // 
            // btn_carp
            // 
            this.btn_carp.AutoSize = true;
            this.btn_carp.ForeColor = System.Drawing.Color.White;
            this.btn_carp.Location = new System.Drawing.Point(142, 662);
            this.btn_carp.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.btn_carp.Name = "btn_carp";
            this.btn_carp.Size = new System.Drawing.Size(304, 41);
            this.btn_carp.TabIndex = 17;
            this.btn_carp.TabStop = true;
            this.btn_carp.Text = "Sierpinski Carpet";
            this.btn_carp.UseVisualStyleBackColor = true;
            // 
            // RecursiveImaging
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(19F, 37F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Navy;
            this.ClientSize = new System.Drawing.Size(1830, 1204);
            this.Controls.Add(this.btn_carp);
            this.Controls.Add(this.label8);
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
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(10, 9, 10, 9);
            this.Name = "RecursiveImaging";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Text = "Recursive Imaging";
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
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.RadioButton btn_carp;
    }
}

