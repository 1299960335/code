using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace 用户界面
{
    class Dao
    {
        public SqlConnection connect()
        {
            string str = "Data Source = LAPTOP-9S4E9RQP; Initial Catalog = Demo; Integrated Security = True";
            SqlConnection sc = new SqlConnection(str);
            sc.Open();//打开数据库链接
            return sc;
        }
        public SqlCommand command(string sql)
        {
            SqlCommand cmd = new SqlCommand(sql, connect());
            return cmd;
        }
        //用于delete updata insert，返回受影响的行数
        public int Execute(string sql)
        {
            return command(sql).ExecuteNonQuery();
        }
        //用于select，返回sqldataReader对象，包含select到的数据
        public SqlDataReader read(string sql)
        {
            return command(sql).ExecuteReader();
        }
    }
}
