#pragma once

template <typename T>
class singletonBase
{
protected:
	static T* m_singleton;

	singletonBase() {};
	~singletonBase() {};

public:
	static T* getSingleton();
	void releasesingleton();
};

template <typename T>
T* singletonBase<T>::m_singleton = 0;

template <typename T>
T* singletonBase<T>::getSingleton()
{
	if (!m_singleton)
		m_singleton = new T;

	return m_singleton;
}

template <typename T>
void singletonBase<T>::releasesingleton()
{
	if (m_singleton)
	{
		delete m_singleton;
		m_singleton = 0;
	}
}