<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>

<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>列表详细页 </title>
	<link rel="stylesheet" type="text/css" href="../css/style.css">
	<link rel="stylesheet" type="text/css" href="../css/base.css">
	<link rel="stylesheet" type="text/css" href="../css/detail.css">
	 <script src="echarts.min.js"></script>
	 <script src="jquery-1.11.1.js" 
	 type="text/javascript">
	</script>
	
</head>
<body>
	<div class="top">		
	</div>
	<div class="header">
		<div class="center">
			<span>长输管道电流电压信息采集</span>
			<img src="../images/by.png">
		</div>
	</div>	
        <div id="content-l">
           <div class="list-content">
                <p style ="margin-left:550px;margin-top:20px;">阴极输出保护电流直流</p>
                <div style =" border:1px solid black;height:800px;width:1200px;background-color:#ECF5FF;margin-top:20px;">
                     <div style="">   
                    <a href="getDevDetail1Action.action">管道电位直流电压</a>&nbsp&nbsp&nbsp&nbsp
                     <a href="getDevDetail2Action.action">管道电位交流RMS值</a>&nbsp&nbsp&nbsp&nbsp
                     <a href="getDevDetail3Action.action">阴极输出保护直流</a>&nbsp&nbsp&nbsp&nbsp
                     <a href="getDevDetail4Action.action">阴极输出保护交流RMS值</a>&nbsp&nbsp&nbsp&nbsp
                     <a href="getDevDetail5Action.action">杂散电流直流电压</a>&nbsp&nbsp&nbsp&nbsp
                     <a href="getDevDetail6Action.action">杂散电流交流电压RMS值</a>&nbsp&nbsp&nbsp&nbsp                                               
		                <div id="main" style="width: 600px;height:400px;margin-left:300px;"></div>	
		                <table border="1" style="margin-left:350px;">
                           <tr>                                                       
                              <th style="height:50px;width:100px">数据</th>                           
                              <th style="height:50px;width:100px">经度</th>
                              <th style="height:50px;width:100px">纬度</th>
                              <th style="height:50px;width:200px">时间</th>
                            </tr>                           
                            <c:if test="${!empty fal}">
								<s:iterator value="fal" id="fal">  			                				
			                      <tr>                                                       
			                        <td style="height:50px;width:100px"><s:property value="#fal.data3"/> </a></td>
                                    <td style="height:50px;width:100px"><s:property value="#fal.data7"/> </a></td>
                                    <td style="height:50px;width:100px"><s:property value="#fal.data8"/> </a></td>
                                    <td style="height:50px;width:100px"><s:property value="#fal.time"/> </a></td>
                                  </tr>
		                    	</s:iterator>
		                    </c:if>		                                              
                        </table>                   	                                                           
                   </div>                                  
                </div>                
         </div>                              
    <div class="footer">   
    </div>
    </div>
    <script type="text/javascript">    
        // 基于准备好的dom，初始化echarts实例       
        var myChart = echarts.init(document.getElementById('main'));      
        //var chartDate =${time};
        //alert("测试");
        var weight=${data3};
        var time = ${time};
        //对echarts做基础配置
        option={
            xAxis:{
            	name: '时间',
            	//data: ["03-21","03-22","03-23","03-24","03-25"]
                  data:time
            },
            yAxis:{
            	name: 'A',
            },
             series:[
                {
                    name:"设备信息",
                    type:"line",//折线图，还有pie（饼状图），
                    data:weight,
                    itemStyle: {
                        normal: {
                            color: "#2ec7c9",
                            lineStyle: {
                                color: "#B3EE3A"
                            }
                        }
                    },
                    
                    //data: [5, 20, 36, 10, 10, 20]
                }
            ]
        }
        myChart.setOption(option);           
    </script>     
</body>
</html>