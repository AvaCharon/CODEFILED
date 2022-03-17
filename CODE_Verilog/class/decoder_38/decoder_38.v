`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/01 11:23:57
// Design Name: 
// Module Name: decoder_38
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module decoder_38(
    input  wire       clk   ,
	input  wire       rst   ,
	input  wire [2:0] enable,
	input  wire [2:0] switch,
	output reg  [7:0] led
    );
    
    wire rst_n = ~rst;
    integer i;
    
    always@(enable or rst_n or switch)begin
        if(rst_n)begin
            if(enable==3'b100)begin
                for(i=0;i<8;i=i+1)begin
                    if(switch==i)led[i]=0;
                    else led[i]=1;
                end
            end 
            else led=8'b11111111;
        end
        else led=8'b11111111;
    end
endmodule
