mm2: source.o helpers.o circularQueue.o producer.o consumer.o
	gcc -o mm2 source.o helpers.o circularQueue.o producer.o consumer.o

producer.o: producer.c header.h
	gcc -c producer.c

source.o: source.c header.h
	gcc -c source.c

helpers.o: helpers.c header.h
	gcc -c helpers.c

circularQueue.o: circularQueue.c header.h
	gcc -c circularQueue.c

consumer.o: consumer.c header.h
	gcc -c consumer.c

clean:
	-rm -f *.o mm2
