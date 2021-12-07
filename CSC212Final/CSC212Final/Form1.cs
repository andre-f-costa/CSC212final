using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace CSC212Final
{
    public partial class RecursiveImaging : Form
    {
        public RecursiveImaging()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (btn_hil.Checked == true)
            {
                btn_ser.Checked = false;
                btn_koch.Checked = false;
                btn_carp.Checked = false;
                txt_iterations.Enabled = true;
                txt_size.Enabled = true;
                txt_iterations.BackColor = Color.White;
                txt_size.BackColor = Color.White;

            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (btn_ser.Checked == true)
            {
                btn_hil.Checked = false;
                btn_koch.Checked = false;
                btn_carp.Checked = false;
                txt_iterations.Enabled = true;
                txt_size.Enabled = true;
                txt_iterations.BackColor = Color.White;
                txt_size.BackColor = Color.White;
            }
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (btn_koch.Checked == true)
            {
                btn_hil.Checked = false;
                btn_ser.Checked = false;
                btn_carp.Checked = false;
                txt_iterations.Enabled = false;
                txt_size.Enabled = false;
                txt_iterations.BackColor = Color.Gray;
                txt_size.BackColor = Color.Gray;
                txt_size.Text = null;
                txt_iterations.Text = null;
            }
        }
        private void btn_carp_CheckedChanged(object sender, EventArgs e)
        {
            if (btn_carp.Checked == true)
            {
                btn_hil.Checked = false;
                btn_koch.Checked = false;
                btn_ser.Checked = false;
                txt_iterations.Enabled = true;
                txt_size.Enabled = true;
                txt_iterations.BackColor = Color.White;
                txt_size.BackColor = Color.White;
            }
        }
        string prog;
        private void button1_Click(object sender, EventArgs e)
        {
            if (Int32.Parse(txt_size.Text) > 10000 && btn_hil.Checked == true)
            {
                // Initializes the variables to pass to the MessageBox.Show method.
                string message = "For Hilbert curve you cannot have a size value greater than 10,000. Please try again with a value less than 10,000.";
                string caption = "Error Detected in Input";
                MessageBoxButtons buttons = MessageBoxButtons.OK;
                DialogResult result;

                // Displays the MessageBox.
                result = MessageBox.Show(message, caption, buttons);
                if (result == System.Windows.Forms.DialogResult.Yes)
                {
                    // Closes the parent form.
                    this.Close();
                }
            }
            else if ((Int32.Parse(txt_size.Text) > 4000 || Int32.Parse(txt_size.Text) < 2500 || Int32.Parse(txt_iterations.Text) > 9) && btn_ser.Checked == true)
            {
                // Initializes the variables to pass to the MessageBox.Show method.
                if (Int32.Parse(txt_iterations.Text) > 9)
                {
                    string message = "Too many iterations, try calling with 9 or less iterations!";
                    string caption = "Error Detected in Input";
                    MessageBoxButtons buttons = MessageBoxButtons.OK;
                    DialogResult result;
                    // Displays the MessageBox.
                    result = MessageBox.Show(message, caption, buttons);
                    if (result == System.Windows.Forms.DialogResult.Yes)
                    {
                        // Closes the parent form.
                        this.Close();
                    }
                }
                if (Int32.Parse(txt_size.Text) > 4000 || Int32.Parse(txt_size.Text) < 2500)
                {
                    string message = "Size out of range, try again with a value between 2500 and 4000.";
                    string caption = "Error Detected in Input";
                    MessageBoxButtons buttons = MessageBoxButtons.OK;
                    DialogResult result;
                    // Displays the MessageBox.
                    result = MessageBox.Show(message, caption, buttons);
                    if (result == System.Windows.Forms.DialogResult.Yes)
                    {
                        // Closes the parent form.
                        this.Close();
                    }
                }
            }
            else
            {
                if (btn_hil.Checked == true)
                {
                    //get string name
                    string fileName = "hilbert";
                    string fullPath = Path.GetFullPath(fileName);
                    prog = "/mnt/";
                    char[] characters = fullPath.ToCharArray();
                    for (int i = 0; i < characters.Length; i++)
                    {
                        if (i == 0)
                        {
                            characters[0] = 'c';
                        }
                        if (characters[i] == (char)92)
                        {
                            characters[i] = '/';
                        }
                        if (characters[i] != ':')
                        {
                            prog = prog + characters[i];
                        }
                    }
                    txt_prog.Text = prog;
                }
                else if (btn_koch.Checked == true)
                {
                    //get string name
                    string fileName = "koch";
                    string fullPath = Path.GetFullPath(fileName);
                    prog = "/mnt/";
                    char[] characters = fullPath.ToCharArray();
                    for (int i = 0; i < characters.Length; i++)
                    {
                        if (i == 0)
                        {
                            characters[0] = 'c';
                        }
                        if (characters[i] == (char)92)
                        {
                            characters[i] = '/';
                        }
                        if (characters[i] != ':')
                        {
                            prog = prog + characters[i];
                        }
                    }
                    txt_prog.Text = prog;
                }
                else if (btn_ser.Checked == true)
                {
                    //get string name
                    string fileName = "s-triangle";
                    string fullPath = Path.GetFullPath(fileName);
                    prog = "/mnt/";
                    char[] characters = fullPath.ToCharArray();
                    for (int i = 0; i < characters.Length; i++)
                    {
                        if (i == 0)
                        {
                            characters[0] = 'c';
                        }
                        if (characters[i] == (char)92)
                        {
                            characters[i] = '/';
                        }
                        if (characters[i] != ':')
                        {
                            prog = prog + characters[i];
                        }
                    }
                    txt_prog.Text = prog;
                }
                else if (btn_carp.Checked == true)
                {
                    //get string name
                    string fileName = "s-carpet";
                    string fullPath = Path.GetFullPath(fileName);
                    prog = "/mnt/";
                    char[] characters = fullPath.ToCharArray();
                    for (int i = 0; i < characters.Length; i++)
                    {
                        if (i == 0)
                        {
                            characters[0] = 'c';
                        }
                        if (characters[i] == (char)92)
                        {
                            characters[i] = '/';
                        }
                        if (characters[i] != ':')
                        {
                            prog = prog + characters[i];
                        }
                    }
                    txt_prog.Text = prog;
                }
                //string prog = txt_prog.Text;
                string output = txt_output.Text;
                Process p = new Process();
                ProcessStartInfo info = new ProcessStartInfo();
                info.FileName = "ubuntu.exe";
                info.RedirectStandardInput = true;
                info.UseShellExecute = false;

                p.StartInfo = info;
                p.Start();

                if (btn_hil.Checked == true)
                {
                    using (StreamWriter sw = p.StandardInput)
                    {
                        if (sw.BaseStream.CanWrite)
                        {
                            sw.WriteLine(prog + " " + output + " " + txt_size.Text + " " + txt_iterations.Text);
                        }
                    }
                }
                else if (btn_koch.Checked == true)
                {
                    using (StreamWriter sw = p.StandardInput)
                    {
                        if (sw.BaseStream.CanWrite)
                        {
                            sw.WriteLine(prog);
                        }
                    }
                }
                else if (btn_ser.Checked == true)
                {
                    using (StreamWriter sw = p.StandardInput)
                    {
                        if (sw.BaseStream.CanWrite)
                        {
                            sw.WriteLine(prog + " " + txt_size.Text + " " + txt_size.Text + " " + txt_iterations.Text + " " + output + " ");
                        }
                    }
                }
                else if (btn_carp.Checked == true)
                {
                    using (StreamWriter sw = p.StandardInput)
                    {
                        if (sw.BaseStream.CanWrite)
                        {
                            sw.WriteLine(prog + " " + txt_size.Text + " " + txt_iterations.Text + " " + output + " ");
                        }
                    }
                }
            }
        }

        private void txt_output_TextChanged(object sender, EventArgs e)
        {

        }

        private void txt_size_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
