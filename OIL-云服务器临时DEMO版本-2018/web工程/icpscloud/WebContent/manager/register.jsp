<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>公司注册</title>


<script>
	function check() {
		if (document.getElementById("password1").value == document
				.getElementById("password2").value)
			return;
		else {
			alert("密码不匹配！");
			$("submit").disable = true;
			return;
		}
	}

</script>


</head>
<body>


	<!-- <form action="companyregist.action" method="post">   -->
	<form action="companyregist.action" method="post">
		<table>
			<tr>
				<td colspan="2">公司注册</td>
			</tr>
			<tr>
				<td>公司名称：</td>
				<td><input type="text" id="companyName" name="companyName" /></td>
			</tr>
			<tr>
				<td>密码：</td>
				<td><input type="password" id="password1" name="password1" /></td>
			</tr>
			<tr>
				<td>确认密码：</td>
				<td><input type="password" id="password2" name="password2" /></td>
			</tr>

			<tr>
				<td colspan="2">
					<input type="submit" value="注册" onclick="check()" id="submit"/>
					<a href="login.jsp">返回</a>
				</td>
			</tr>
		</table>
	</form>

</body>
</html>