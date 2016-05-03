pipeline: main.o simulator.o IF_stage.o ID_stage.o EX_stage.o DM_stage.o WB_stage.o IF_ID_buffer.o ID_EX_buffer.o EX_DM_buffer.o DM_WB_buffer.o instruction.o regfile.o memory.o
	g++ -o pipeline main.o simulator.o IF_stage.o ID_stage.o EX_stage.o DM_stage.o WB_stage.o IF_ID_buffer.o ID_EX_buffer.o EX_DM_buffer.o DM_WB_buffer.o instruction.o regfile.o memory.o -g
main.o: main.cpp simulator.h
	g++ -c main.cpp -g
simulator.o: simulator.cpp simulator.h IF_stage.h ID_stage.h EX_stage.h DM_stage.h WB_stage.h IF_ID_buffer.h ID_EX_buffer.h EX_DM_buffer.h DM_WB_buffer.h instruction.h regfile.h memory.h
	g++ -c simulator.cpp -g
instruction.o: instruction.cpp instruction.h
	g++ -c instruction.cpp -g
regfile.o: regfile.cpp regfile.h
	g++ -c regfile.cpp -g
memory.o: memory.cpp memory.h
	g++ -c memory.cpp -g
IF_stage.o: IF_stage.cpp IF_stage.h ID_EX_buffer.h
	g++ -c IF_stage.cpp -g
ID_stage: ID_stage.cpp ID_stage.h IF_ID_buffer.h EX_DM_buffer.h DM_WB_buffer.h
	g++ -c ID_stage.cpp -g
EX_stage: ID_EX_buffer.h EX_DM_buffer.h EX_stage.h
	g++ -c EX_stage.cpp -g
DM_stage: EX_DM_buffer.h DM_stage.h
	g++ -c DM_stage.cpp -g
WB_stage: DM_WB_buffer.h WB_stage.h
	g++ -c WB_stage.cpp -g
IF_ID_buffer: IF_ID_buffer.h IF_stage.h
	g++ -c IF_ID_buffer.cpp -g
ID_EX_buffer: ID_EX_buffer.h ID_stage.h
	g++ -c ID_EX_buffer.cpp -g
EX_DM_buffer: EX_DM_buffer.h EX_stage.h
	g++ -c EX_DM_buffer.cpp -g
DM_WB_buffer: DM_WB_buffer.h DM_stage.h
	g++ -c DM_WB_buffer.cpp -g
clean:
	rm -f pipeline main.o simulator.o IF_stage.o ID_stage.o EX_stage.o DM_stage.o WB_stage.o IF_ID_buffer.o ID_EX_buffer.o EX_DM_buffer.o DM_WB_buffer.o instruction.o regfile.o memory.o
