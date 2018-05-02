<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>公司登录页面</title>
</head>
<body>
<form action="companylogin" method="post">  
        <table>  
            <tr>  
                <td colspan="2">登录窗口</td>  
            </tr>  
            <tr>  
                <td>用户名：</td>  
                <td><input type="text" name="companyName" />  
                </td>  
            </tr>  
            <tr>  
                <td>密码：</td>  
                <td><input type="password" name="password" />  
                </td>  
            </tr>  
            <tr>  
                <td colspan="2"><input type="submit" value="登录" /> <a href="register.jsp">注册</a>  
                </td>  
            </tr>  
        </table>  
        <TABLE>
            <TR>
            <TD align="center" valign="middle"><font size="2" color="RED">${msg}</font></TD>
            <TD align="center" valign="middle"><font size="2" color="RED">下次下次想</font></TD>
            </TR>
        </TABLE>
</form>  
<jsp:include page = "footer.jsp"/>
</body>
</html>


