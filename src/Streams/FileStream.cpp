#include "Aeon/Aeon.h"
#include "Aeon/Streams/FileStream.h"
#include "Aeon/Console/Console.h"

namespace Aeon
{

FileStream::FileStream(const std::string &path, int access_mode /*= AccessMode::READ*/)
:
Stream(access_mode),
file_(NULL)
{
	name_ = path;

	if(access_mode == (AccessMode::READ | AccessMode::WRITE))
	{
		Console::error("FileStream: Invalid access mode: Read+Write on file %s.", name_.c_str());
		return;
	}

	__open_file();
}

FileStream::~FileStream()
{
}

void FileStream::__open_file()
{
	if (access_mode_ == AccessMode::READ)
		file_ = fopen(name_.c_str(), "rb");
	else
		file_ = fopen(name_.c_str(), "wb");

	if (!file_)
	{
		Console::error("FileStream: Could not open file: %s", name_.c_str());
		return;
	}

	if(access_mode_ == AccessMode::READ)
		__calculate_file_size();
}

void FileStream::__calculate_file_size()
{
	if (!file_)
	{
		Console::error("FileStream: Size requested on unopened file.");
		return;
	}

	if (!seek(0, SeekDirection::End))
		Console::error("Could not determine file size for file: %s. Seek end failed.", name_.c_str());

	size_ = ftell(file_);

	if (size_ == 0)
		Console::warning("FileStream: File is empty: %s", name_.c_str());

	if (!seek(0, SeekDirection::Begin))
		Console::error("Could not determine file size for file: %s. Seek begin failed.", name_.c_str());
}

size_t FileStream::read(void *buffer, size_t count)
{
	if(!file_)
	{
		Console::error("FileStream: Read on unopened file.");
		return 0;
	}

	if(access_mode_ != AccessMode::READ)
	{
		Console::error("FileStream: Can not read from file in write mode for file %s.", name_.c_str());
		return 0;
	}

	if (!buffer)
	{
		Console::error("FileStream: Input buffer is NULL.");
		return 0;
	}

	if (count == 0)
	{
		Console::warning("FileStream: Tried writing 0 bytes.");
		return 0;
	}

	return fread(buffer, 1, count, file_);
}

size_t FileStream::read_line(std::string &str)
{
	if (!file_)
	{
		Console::error("FileStream: Read on unopened file.");
		return 0;
	}

	if (access_mode_ != AccessMode::READ)
	{
		Console::error("FileStream: Can not read from file in write mode for file %s.", name_.c_str());
		return 0;
	}

	//AEON_FILE_LINE_BUFFER_SIZE
	std::string line;

	for (int i = 0; i < AEON_STREAM_MAX_TEXT_LINE_LENGTH; ++i)
	{
		int c = fgetc(file_);

		if(c == EOF)
			break;

		if(c == '\n')
			break;

		line += (char) c;
	}

	str = line;

	return line.length();
}

size_t FileStream::write(const void *buffer, size_t count)
{
	if (!file_)
	{
		Console::error("FileStream: Write on unopened file.");
		return 0;
	}

	if (access_mode_ != AccessMode::WRITE)
	{
		Console::error("FileStream: Can not write to file in read mode for file %s.", name_.c_str());
		return 0;
	}

	if (!buffer)
	{
		Console::error("FileStream: Input buffer is NULL.");
		return 0;
	}

	if (count == 0)
	{
		Console::warning("FileStream: Tried writing 0 bytes.");
		return 0;
	}

	return fwrite(buffer, 1, count, file_);
}

bool FileStream::seek(size_t pos, SeekDirection direction)
{
	if(!file_)
	{
		Console::error("FileStream: Seek on unopened file.");
		return false;
	}

	switch (direction)
	{
		case SeekDirection::Begin:
		{
			return fseek(file_, (long) pos, SEEK_SET) == 0;
		}break;
		case SeekDirection::Current:
		{
			return fseek(file_, (long) pos, SEEK_CUR) == 0;
		}break;
		case SeekDirection::End:
		{
			return fseek(file_, (long) pos, SEEK_END) == 0;
		}break;
	};

	return false;
}

size_t FileStream::tell() const
{
	if(!file_)
	{
		Console::error("FileStream: Tell on unopened file.");
		return 0;
	}

	return ftell(file_);
}

bool FileStream::eof() const
{
	if (!file_)
	{
		Console::error("FileStream: EOF on unopened file.");
		return true;
	}

	return (feof(file_) != 0);
}

void FileStream::close()
{
	if (!file_)
	{
		Console::error("FileStream: Close on unopened file.");
		return;
	}

	fclose(file_);
	file_ = NULL;
}

void FileStream::flush()
{
	if (!file_)
	{
		Console::error("FileStream: Close on unopened file.");
		return;
	}

	fflush(file_);
}

bool FileStream::good()
{
	return file_ != NULL;
}

} //namespace Aeon
