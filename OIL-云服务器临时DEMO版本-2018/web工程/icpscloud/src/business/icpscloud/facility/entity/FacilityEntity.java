/**
 * 
 */
package business.icpscloud.facility.entity;
/**
 * @author LiPeiXu
 * @ModifyDate 2017Äê6ÔÂ20ÈÕ
 */
public class FacilityEntity {
	 private Integer DataID;
     private String Data1;
	 private String Data2;
	 private String Data3;
     private String Data4;
     private String Data5;
     private String Data6;
     private String Data7;
     private String Data8;
     private String Time;
	/**
	 * @param i
	 * @param string
	 * @param string2
	 * @param string3
	 * @param string4
	 * @param string5
	 * @param string6
	 * @param string7
	 */
	public FacilityEntity(int i, String string1, String string2, String string3, String string4, String string5,
			String string6) {
		DataID=i;
		Data1 = string1;
		Data2 = string2;
		Data3 = string3;
		Data4 = string4;
		Data5 = string5;
		Data6 = string6;
	}
	
	/**
	 * 
	 */
	public FacilityEntity() {
		
	}
	public Integer getDataID() {
		return DataID;
	}
	public void setDataID(Integer dataID) {
		DataID = dataID;
	}
	
	public String getData1() {
		return Data1;
	}
	public void setData1(String data1) {
		Data1 = data1;
	}
	public String getData2() {
		return Data2;
	}
	public void setData2(String data2) {
		Data2 = data2;
	}
	public String getData3() {
		return Data3;
	}
	public void setData3(String data3) {
		this.Data3 = data3;
	}
	public String getData4() {
		return Data4;
	}
	public void setData4(String data4) {
		Data4 = data4;
	}
	public String getData5() {
		return Data5;
	}
	public void setData5(String data5) {
		Data5 = data5;
	}
	public String getData6() {
		return Data6;
	}
	public void setData6(String data6) {
		Data6 = data6;
	}
	public String getData7() {
		return Data7;
	}
	public void setData7(String data7) {
		Data7 = data7;
	}
	public String getData8() {
		return Data8;
	}
	public void setData8(String data8) {
		Data8 = data8;
	} 
	public String getTime() {
		return Time;
	}
	public void setTime(String time) {
		Time = time;
	}
}
